    #include <stdio.h>
    #include <stdlib.h>
    #include <libelf.h>    //list functions
    #include <gelf.h>    //list functions
    #include <capstone/capstone.h>
    #include <unistd.h>
    #include <sys/ptrace.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/user.h>
    #include <fcntl.h>
    #include <string.h>
    #include <signal.h>
    #include <errno.h>
    #include <elf.h>
    #include <readline/readline.h>
    #include <readline/history.h>
    #include <Python.h>

    #define MAX_BREAKPOINTS 100
    #define MAX_CMD_LEN 1024
    #define MAX_FUNC_LEN 1024

    typedef struct {
        unsigned long address;
        unsigned char original_byte; // Store the original byte at the breakpoint
    } Breakpoint;

    Breakpoint breakpoints[MAX_BREAKPOINTS];
    int breakpoint_count = 0;

    // Function prototypes
    void show_manual();
    void list_functions(const char *program);
    void disassemble_function(const char *program, const char *function);
    void view_variable(pid_t child_pid, unsigned long address);
    void analyze_elf(const char *filename);
    void generate_cfg(const char *program);
    void show_registers(pid_t child_pid);
    void set_breakpoint(pid_t child_pid, const char *target, const char *program_name);
    void continue_execution(pid_t child_pid);
    void list_breakpoints();
    void remove_breakpoint(pid_t child_pid, const char *target);
    void dump_memory(pid_t child_pid, unsigned long address, size_t length);
    void single_step(pid_t child_pid);
    void backtrace(pid_t child_pid);
    void monitor_syscalls(pid_t child_pid);
    void show_current_address(pid_t child_pid);
    void execute_command(pid_t child_pid, const char *command, const char *program);
    void start_debugger(const char *program);
    void interactive_shell();
    void init_python();
    void execute_script(const char *script);
    void close_python();
    unsigned long resolve_function_address(const char *function_name, const char *program_name);


    // Python Scripting Support
    void init_python() {
        Py_Initialize();
        if (!Py_IsInitialized()) {
            fprintf(stderr, "Error initializing Python interpreter\n");
            return;
        }
        PyRun_SimpleString("print('Python scripting enabled!')");
    }
    void list_functions(const char *program) {
        Elf *elf;
        int fd;
    
        if (elf_version(EV_CURRENT) == EV_NONE) {
            fprintf(stderr, "Failed to initialize ELF library: %s\n", elf_errmsg(-1));
            return;
        }

        fd = open(program, O_RDONLY);
        if (fd < 0) {
            perror("Error opening ELF file");
            return;
        }

        elf = elf_begin(fd, ELF_C_READ, NULL);
        if (!elf) {
            fprintf(stderr, "elf_begin() failed: %s\n", elf_errmsg(-1));
            close(fd);
            return;
        }
        Elf_Scn *scn = NULL;
        GElf_Shdr shdr;

        printf("Functions in %s:\n", program);

        // Scan sections for symbols (SHT_SYMTAB or SHT_DYNSYM)
        while ((scn = elf_nextscn(elf, scn)) != NULL) {
            gelf_getshdr(scn, &shdr);
            if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM) {
                Elf_Data *data = elf_getdata(scn, NULL);
                int symbols = shdr.sh_size / shdr.sh_entsize;

                for (int i = 0; i < symbols; i++) {
                    GElf_Sym sym;
                    gelf_getsym(data, i, &sym);
                    
                    if (sym.st_value != 0 && (ELF32_ST_TYPE(sym.st_info) == STT_FUNC || ELF32_ST_TYPE(sym.st_info) == STT_NOTYPE)) {
                        char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
                        if (name && strlen(name) > 0) {
                            printf("0x%lx  %s\n", sym.st_value, name);
                        }
                    }
                }
            }
        }

        elf_end(elf);
        close(fd);
    }

    void disassemble_function(const char *program, const char *input) {
        int fd;
        Elf *elf;
        Elf_Scn *scn = NULL;
        GElf_Shdr shdr;
        csh handle;
        cs_insn *insn;
        size_t count;

        unsigned long target_address = 0;
        int is_address = sscanf(input, "%lx", &target_address); // Check if input is an address

        if (elf_version(EV_CURRENT) == EV_NONE) {
            fprintf(stderr, "Failed to initialize ELF library: %s\n", elf_errmsg(-1));
            return;
        }

        fd = open(program, O_RDONLY);
        if (fd < 0) {
            perror("Error opening ELF file");
            return;
        }

        elf = elf_begin(fd, ELF_C_READ, NULL);
        if (!elf) {
            fprintf(stderr, "elf_begin() failed: %s\n", elf_errmsg(-1));
            close(fd);
            return;
        }

        while ((scn = elf_nextscn(elf, scn)) != NULL) {
            gelf_getshdr(scn, &shdr);
            if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM) {
                Elf_Data *data = elf_getdata(scn, NULL);
                int symbols = shdr.sh_size / shdr.sh_entsize;

                for (int i = 0; i < symbols; i++) {
                    GElf_Sym sym;
                    gelf_getsym(data, i, &sym);
                    char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);

                    // Match by function name or address
                    if ((is_address && sym.st_value == target_address) || (!is_address && name && strcmp(name, input) == 0)) {
                        printf("\nDump of assembler code for function %s (or address 0x%lx):\n", name ? name : "(unknown)", sym.st_value);
                        printf("   Address           Offset   Instruction\n");

                        if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK) {
                            fprintf(stderr, "Capstone initialization failed.\n");
                            elf_end(elf);
                            close(fd);
                            return;
                        }

                        cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);

                        Elf_Scn *text_scn = elf_getscn(elf, sym.st_shndx);
                        Elf_Data *text_data = elf_getdata(text_scn, NULL);
                        GElf_Shdr text_shdr;
                        gelf_getshdr(text_scn, &text_shdr);

                        size_t offset = sym.st_value - text_shdr.sh_addr;
                        unsigned char *code = (unsigned char *)text_data->d_buf + offset;
                        size_t code_size = sym.st_size;

                        count = cs_disasm(handle, code, code_size, sym.st_value, 0, &insn);
                        if (count > 0) {
                            for (size_t j = 0; j < count; j++) {
                                printf("   0x%016lx    %-7d  %-7s %s\n",
                                    insn[j].address,
                                    (int)(insn[j].address - sym.st_value), // Offset
                                    insn[j].mnemonic,
                                    insn[j].op_str);
                            }
                            cs_free(insn, count);
                        } else {
                            fprintf(stderr, "Failed to disassemble.\n");
                        }

                        printf("End of assembler dump.\n");

                        cs_close(&handle);
                        elf_end(elf);
                        close(fd);
                        return;
                    }
                }
            }
        }

        printf("Function %s (or address 0x%lx) not found in %s.\n", input, target_address, program);
        elf_end(elf);
        close(fd);
    }
    void continue_execution(pid_t child_pid) {
        int status;

        printf("Continuing execution...\n");

        // Continue execution
        if (ptrace(PTRACE_CONT, child_pid, NULL, NULL) == -1) {
            perror("ptrace CONT failed");
            return;
        }

        // Wait for the child process to stop or exit
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Program exited with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Program terminated by signal: %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            if (WSTOPSIG(status) == SIGTRAP) {
                printf("Breakpoint hit!\n");
                show_current_address(child_pid); // Show where the program stopped
                show_registers(child_pid);       // Display register values at this point
            } else {
                printf("Program stopped by signal: %d\n", WSTOPSIG(status));
            }
        } else {
            printf("Unknown state. Debugged process may have stopped unexpectedly.\n");
        }
    }
    void view_variable(pid_t child_pid, unsigned long address) {
        long data = ptrace(PTRACE_PEEKTEXT, child_pid, (void *)address, NULL);
        if (data == -1 && errno) {
        perror("ptrace PEEKTEXT failed");
        return;
    }
    printf("Value at address 0x%lx: 0x%lx\n", address, data);
    }
    void show_manual() {
        printf("Debugger Manual:\n");
        printf("Commands available:\n");
        printf("  quit                - Exit the debugger\n");
        printf("  break <addr>        - Set a breakpoint at address\n");
        printf("  list                - List all breakpoints\n");
        printf("  remove <addr>       - Remove a breakpoint at address\n");
        printf("  dump <addr> <len>   - Dump memory from address\n");
        printf("  step                - Execute one instruction and move to the next\n");
        printf("  current             - Show the current instruction pointer (RIP)\n");
        printf("  regs                - Show all register values\n");
        printf("  backtrace           - Show the stack backtrace\n");
        printf("  syscalls            - Monitor system calls made by the program\n");
        printf("  list functions      - List all functions in the program's ELF file\n");
        printf("  disassemble <func>  - Disassemble a specific function\n");
        printf("  view <addr>         - View the value of a variable at the specified memory address\n");
        printf("  analyze             - Analyze the ELF file structure\n");
        printf("  cfg                 - Generate a control flow graph (CFG) of the program\n");
        printf("  execute <script>    - Execute a Python script for extended functionality\n");
        printf("\n");
        printf("Examples:\n");
        printf("  break 0x401000      - Set a breakpoint at memory address 0x401000\n");
        printf("  list                - Display all active breakpoints\n");
        printf("  remove 0x401000     - Remove the breakpoint at address 0x401000\n");
        printf("  dump 0x404000 64    - Dump 64 bytes of memory starting from address 0x404000\n");
        printf("  step                - Execute the next instruction\n");
        printf("  current             - Display the current instruction pointer\n");
        printf("  regs                - Show the values of all CPU registers\n");
        printf("  disassemble main    - Disassemble the 'main' function\n");
        printf("  view 0x403020       - View the variable value at address 0x403020\n");
        printf("  analyze             - Show ELF header and section details\n");
        printf("  cfg                 - Generate a CFG using objdump and cflow\n");
        printf("  execute script.py   - Run the Python script 'script.py'\n");
        printf("\n");
        printf("Use these commands interactively in the debugger shell.\n");
    }

    void execute_script(const char *script) {
        FILE *fp = fopen(script, "r");
        if (!fp) {
            perror("Error opening script");
            return;
        }
        PyRun_SimpleFile(fp, script);
        fclose(fp);
    }

    void close_python() {
        Py_Finalize();
    }

    // ELF Analysis
    void analyze_elf(const char *filename) {
        int fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("Error opening file");
            return;
        }

        Elf64_Ehdr ehdr;
        if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
            perror("Error reading ELF header");
            close(fd);
            return;
        }

        if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
            printf("Not a valid ELF file.\n");
            close(fd);
            return;
        }

        printf("ELF Header:\n");
        printf("  Entry point: 0x%lx\n", ehdr.e_entry);
        printf("  Program header offset: %ld\n", ehdr.e_phoff);
        printf("  Section header offset: %ld\n", ehdr.e_shoff);
        printf("  Number of section headers: %d\n", ehdr.e_shnum);

        lseek(fd, ehdr.e_shoff, SEEK_SET);
        Elf64_Shdr shdrs[ehdr.e_shnum];
        if (read(fd, shdrs, ehdr.e_shnum * sizeof(Elf64_Shdr)) != ehdr.e_shnum * sizeof(Elf64_Shdr)) {
            perror("Error reading section headers");
            close(fd);
            return;
        }

        Elf64_Shdr shstrtab = shdrs[ehdr.e_shstrndx];
        char *shstrtab_data = malloc(shstrtab.sh_size);
        lseek(fd, shstrtab.sh_offset, SEEK_SET);
        read(fd, shstrtab_data, shstrtab.sh_size);

        printf("\nSections:\n");
        for (int i = 0; i < ehdr.e_shnum; i++) {
            printf("  [%2d] %s\n", i, &shstrtab_data[shdrs[i].sh_name]);
        }

        free(shstrtab_data);
        close(fd);
    }

    // Control Flow Graph (CFG) Visualization
    void generate_cfg(const char *program) {
        char cmd[MAX_CMD_LEN];

        // Use objdump to disassemble the binary and filter valid instructions
        snprintf(cmd, sizeof(cmd),
                "objdump -d -M intel %s | awk '/<.*>:/{print $1 \" -> \" $2}' > cfg.dot && dot -Tpng cfg.dot -o cfg.png",
                program);

        printf("Generating CFG and saving to cfg.png...\n");
        int ret = system(cmd);
        if (ret != 0) {
            fprintf(stderr, "Error generating CFG. Make sure objdump, awk, and dot are installed.\n");
        } else {
            printf("CFG generated successfully. Open cfg.png to view the graph.\n");
        }
    }



    // Debugger Commands
    void show_registers(pid_t child_pid) {
        struct user_regs_struct regs;
        if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1) {
            perror("ptrace GETREGS failed");
            return;
        }
        printf("Registers:\n");
        printf("RIP: 0x%llx  RSP: 0x%llx  RBP: 0x%llx\n", regs.rip, regs.rsp, regs.rbp);
        printf("RAX: 0x%llx  RBX: 0x%llx  RCX: 0x%llx  RDX: 0x%llx\n", regs.rax, regs.rbx, regs.rcx, regs.rdx);
        printf("RSI: 0x%llx  RDI: 0x%llx\n", regs.rsi, regs.rdi);
        printf("R8:  0x%llx  R9:  0x%llx  R10: 0x%llx  R11: 0x%llx\n", regs.r8, regs.r9, regs.r10, regs.r11);
        printf("R12: 0x%llx  R13: 0x%llx  R14: 0x%llx  R15: 0x%llx\n", regs.r12, regs.r13, regs.r14, regs.r15);
        printf("EFLAGS: 0x%llx\n", regs.eflags);
    }


    void set_breakpoint(pid_t child_pid, const char *target, const char *program_name) {
        unsigned long address = 0;

        // Parse the target as an address or resolve it as a function name
        if (sscanf(target, "%lx", &address) == 1) {
            printf("Parsed address: 0x%lx\n", address);
        } else {
            address = resolve_function_address(target, program_name);
            if (address == 0) {
                printf("Failed to resolve function: %s\n", target);
                return;
            }
            printf("Resolved function '%s' to address: 0x%lx\n", target, address);
        }

        // Check for duplicate breakpoints
        for (int i = 0; i < breakpoint_count; i++) {
            if (breakpoints[i].address == address) {
                printf("Breakpoint already exists at address: 0x%lx\n", address);
                return;
            }
        }

        // Read the instruction at the target address
        long data = ptrace(PTRACE_PEEKTEXT, child_pid, (void *)address, NULL);
        if (data == -1 && errno) {
            perror("Error: ptrace PEEKTEXT failed");
            return;
        }

        // Save the original byte and replace it with INT3 (0xCC)
        unsigned char *byte = (unsigned char *)&data;
        breakpoints[breakpoint_count].address = address;
        breakpoints[breakpoint_count].original_byte = *byte;

        *byte = 0xCC; // Replace with breakpoint instruction
        if (ptrace(PTRACE_POKETEXT, child_pid, (void *)address, (void *)data) == -1) {
            perror("Error: ptrace POKETEXT failed");
            return;
        }

        breakpoint_count++;
        printf("Breakpoint set at address: 0x%lx\n", address);
    }


    unsigned long resolve_function_address(const char *function_name, const char *program_name) {
        Elf *elf;
        int fd = open(program_name, O_RDONLY);
        if (fd < 0) {
            perror("Error opening ELF file");
            return 0;
        }

        if (elf_version(EV_CURRENT) == EV_NONE) {
            fprintf(stderr, "Error initializing ELF library: %s\n", elf_errmsg(-1));
            close(fd);
            return 0;
        }

        elf = elf_begin(fd, ELF_C_READ, NULL);
        if (!elf) {
            fprintf(stderr, "Error: elf_begin() failed: %s\n", elf_errmsg(-1));
            close(fd);
            return 0;
        }

        Elf_Scn *scn = NULL;
        GElf_Shdr shdr;
        unsigned long address = 0;

        while ((scn = elf_nextscn(elf, scn)) != NULL) {
            if (!gelf_getshdr(scn, &shdr)) {
                fprintf(stderr, "Error: gelf_getshdr() failed: %s\n", elf_errmsg(-1));
                continue;
            }

            if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM) {
                Elf_Data *data = elf_getdata(scn, NULL);
                if (!data) {
                    fprintf(stderr, "Error: elf_getdata() failed\n");
                    continue;
                }

                int symbols = shdr.sh_size / shdr.sh_entsize;
                for (int i = 0; i < symbols; i++) {
                    GElf_Sym sym;
                    if (!gelf_getsym(data, i, &sym)) {
                        fprintf(stderr, "Error: gelf_getsym() failed\n");
                        continue;
                    }

                    char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
                    if (name && strcmp(name, function_name) == 0) {
                        address = sym.st_value;
                        if (sym.st_shndx != SHN_UNDEF) { // For static binaries
                            Elf_Scn *section = elf_getscn(elf, sym.st_shndx);
                            GElf_Shdr section_header;
                            if (section && gelf_getshdr(section, &section_header)) {
                                address += section_header.sh_addr;
                            }
                        }
                        elf_end(elf);
                        close(fd);
                        return address;
                    }
                }
            }
        }

        printf("Function '%s' not found in the ELF symbols.\n", function_name);
        elf_end(elf);
        close(fd);
        return 0;
    }


    void list_breakpoints() {
        if (breakpoint_count == 0) {
            printf("No breakpoints set.\n");
            return;
        }
        printf("Breakpoints:\n");
        for (int i = 0; i < breakpoint_count; i++) {
            printf("%d: Address 0x%lx\n", i, breakpoints[i].address);
        }
    }

    void remove_breakpoint(pid_t child_pid, const char *target) {
        unsigned long address;
        if (sscanf(target, "%lx", &address) == 1) {
            for (int i = 0; i < breakpoint_count; i++) {
                if (breakpoints[i].address == address) {
                    long data = ptrace(PTRACE_PEEKTEXT, child_pid, (void *)address, NULL);
                    if (data == -1 && errno) {
                        perror("ptrace PEEKTEXT failed");
                        return;
                    }
                    unsigned char *byte = (unsigned char *)&data;
                    *byte = breakpoints[i].original_byte;
                    if (ptrace(PTRACE_POKETEXT, child_pid, (void *)address, (void *)data) == -1) {
                        perror("ptrace POKETEXT failed");
                        return;
                    }
                    for (int j = i; j < breakpoint_count - 1; j++) {
                        breakpoints[j] = breakpoints[j + 1];
                    }
                    breakpoint_count--;
                    printf("Breakpoint removed at address: 0x%lx\n", address);
                    return;
                }
            }
            printf("Breakpoint not found at address: 0x%lx\n", address);
        } else {
            printf("Invalid address format.\n");
        }
    }

    void dump_memory(pid_t child_pid, unsigned long address, size_t length) {
        printf("Memory dump at address: 0x%lx\n", address);
        for (size_t i = 0; i < length; i += sizeof(long)) {
            long data = ptrace(PTRACE_PEEKTEXT, child_pid, (void *)(address + i), NULL);
            if (data == -1 && errno) {
                perror("ptrace PEEKTEXT failed");
                break;
            }
            printf("0x%lx: 0x%lx\n", address + i, data);
        }
    }

    void single_step(pid_t child_pid) {
        if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1) {
            perror("ptrace SINGLESTEP failed");
            return;
        }
        int status;
        waitpid(child_pid, &status, 0);
        if (WIFSTOPPED(status)) {
            printf("Single step executed. Child process stopped.\n");
            show_current_address(child_pid);  // Show current address after stepping
        } else if (WIFEXITED(status)) {
            printf("Child process exited.\n");
        }
    }

    void show_current_address(pid_t child_pid) {
        struct user_regs_struct regs;
        if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1) {
            perror("ptrace GETREGS failed");
            return;
        }
        printf("Current Instruction Pointer (RIP): 0x%llx\n", regs.rip);
    }


    void monitor_syscalls(pid_t child_pid) {
        int status;

        while (1) {
            if (waitpid(child_pid, &status, 0) == -1) {
                perror("Error: waitpid failed");
                break;
            }

            if (WIFEXITED(status)) {
                printf("Child process exited\n");
                break;
            }

            struct user_regs_struct regs;
            if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1) {
                perror("Error: ptrace GETREGS failed");
                break;
            }

            printf("System call: %llu\n", regs.orig_rax);

            if (ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL) == -1) {
                perror("Error: ptrace SYSCALL failed");
                break;
            }
        }
    }

    void execute_command(pid_t child_pid, const char *command, const char *program) {
        if (strcmp(command, "quit") == 0) {
            printf("Exiting debugger...\n");
            kill(child_pid, SIGKILL); // Kill the child process
        } else if (strcmp(command, "list") == 0) {
            list_breakpoints();
        } else if (strncmp(command, "remove", 6) == 0) {
            char target[MAX_CMD_LEN];
            if (sscanf(command + 7, "%s", target) == 1) {
                remove_breakpoint(child_pid, target);
            } else {
                printf("Usage: remove <address>\n");
            }
        } else if (strncmp(command, "dump", 4) == 0) {
            unsigned long addr;
            size_t length;
            if (sscanf(command + 5, "%lx %zu", &addr, &length) == 2) {
                dump_memory(child_pid, addr, length);
            } else {
                printf("Usage: dump <address> <length>\n");
            }
        } else if (strcmp(command, "step") == 0) {
            single_step(child_pid);
        } else if (strcmp(command, "regs") == 0) {
            show_registers(child_pid);
        } else if (strcmp(command, "current") == 0) {
            show_current_address(child_pid);
        } else if (strcmp(command, "backtrace") == 0) {
            backtrace(child_pid);
        } else if (strcmp(command, "syscalls") == 0) {
            monitor_syscalls(child_pid);
        } else if (strcmp(command, "list functions") == 0) {
            list_functions(program);
        } else if (strncmp(command, "disassemble", 11) == 0) {
            char function[MAX_CMD_LEN];
            if (sscanf(command + 12, "%s", function) == 1) {
                disassemble_function(program, function);
            } else {
                printf("Usage: disassemble <function_name>\n");
            }
        } else if (strncmp(command, "view", 4) == 0) {
            unsigned long address;
            if (sscanf(command + 5, "%lx", &address) == 1) {
                view_variable(child_pid, address);
            } else {
                printf("Usage: view <address>\n");
            }
        } else if (strcmp(command, "analyze") == 0) {
            analyze_elf(program);
        } else if (strcmp(command, "cfg") == 0) {
            generate_cfg(program);
        } else if (strncmp(command, "execute", 7) == 0) {
            char script[MAX_CMD_LEN];
            if (sscanf(command + 8, "%s", script) == 1) {
                execute_script(script);
            } else {
                printf("Usage: execute <script.py>\n");
            }
        } else if (strcmp(command, "continue") == 0) {
            continue_execution(child_pid);
        }else if (strncmp(command, "break", 5) == 0) {
            char target[MAX_CMD_LEN];
            if (sscanf(command + 6, "%s", target) == 1) {
                set_breakpoint(child_pid, target, program);
            } else {
                printf("Usage: break <address | function_name>\n");
            }
        }else {
            printf("Unknown command: %s\n", command);
        }
    }
    void interactive_shell() {
        char *input;

        printf("Advanced Debugger Interactive Shell\n");
        while ((input = readline("(debugger) > ")) != NULL) {
            if (strlen(input) > 0) {
                add_history(input);
                if (strcmp(input, "quit") == 0) {
                    free(input);
                    break;
                } else {
                    printf("Executing: %s\n", input);
                    // Command execution placeholder
                }
            }
            free(input);
        }
    }
    // Debugger Main Loop
    void start_debugger(const char *program) {
        pid_t child_pid = fork();
        if (child_pid == 0) {
            ptrace(PTRACE_TRACEME, 0, NULL, NULL);
            execlp(program, program, NULL);
            perror("execlp failed");
            exit(1);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            show_manual();
            while (1) {
                char *command = readline("(debugger) > ");
                if (command && strlen(command) > 0) {
                    add_history(command);
                    if (strcmp(command, "quit") == 0) {
                        free(command);
                        break;
                    }
                    execute_command(child_pid, command, program);
                }
                free(command);
            }
        }
    }

    // Main Program
    int main(int argc, char *argv[]) {
        if (argc != 2) {
            printf("Usage: %s <program>\n", argv[0]);
            return 1;
        }
        init_python();
        start_debugger(argv[1]);
        close_python();
        return 0;
    }
