        
        // Python Scripting Support
    void init_python() {
        Py_Initialize();
        if (!Py_IsInitialized()) {
            fprintf(stderr, "Error initializing Python interpreter\n");
            return;
        }
        PyRun_SimpleString("print('Python scripting enabled!')");

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

    void execute_command(pid_t child_pid, const char *command, const char *program) {
        char target[MAX_CMD_LEN];
        unsigned long addr;
        size_t length;

        if (strcmp(command, "quit") == 0) {
            printf("Exiting debugger...\n");
            kill(child_pid, SIGKILL);  // Kill the child process

        } else if (strcmp(command, "list") == 0) {
            list_breakpoints();

        } else if (strncmp(command, "remove", 6) == 0) {
            if (sscanf(command + 7, "%s", target) == 1) {
                remove_breakpoint(child_pid, target);
            } else {
                printf("Usage: remove <address>\n");
            }

        } else if (strncmp(command, "dump", 4) == 0) {
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
            if (sscanf(command + 12, "%s", target) == 1) {
                disassemble_function(program, target);
            } else {
                printf("Usage: disassemble <function_name>\n");
            }

        } else if (strncmp(command, "view", 4) == 0) {
            if (sscanf(command + 5, "%lx", &addr) == 1) {
                view_variable(child_pid, addr);
            } else {
                printf("Usage: view <address>\n");
            }

        } else if (strcmp(command, "analyze") == 0) {
            analyze_elf(program);

        } else if (strcmp(command, "cfg") == 0) {
            generate_cfg(program);

        } else if (strncmp(command, "execute", 7) == 0) {
            if (sscanf(command + 8, "%s", target) == 1) {
                execute_script(target);
            } else {
                printf("Usage: execute <script.py>\n");
            }

        } else if (strcmp(command, "continue") == 0) {
            continue_execution(child_pid);

        } else if (strncmp(command, "break", 5) == 0) {
            if (sscanf(command + 6, "%s", target) == 1) {
                set_breakpoint(child_pid, target, program);
            } else {
                printf("Usage: break <address | function_name>\n");
            }

        } else {
            printf("Unknown command: %s\n", command);
        }
    }
        
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

            // Set ptrace options
            ptrace(PTRACE_SETOPTIONS, child_pid, NULL, PTRACE_O_TRACESYSGOOD | PTRACE_O_TRACEEXIT);
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