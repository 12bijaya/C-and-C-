#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;

    FILE *file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Error opening /etc/passwd");
        return 1;
    }
    printf("Contents of /etc/passwd:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    file = fopen("/etc/hostname", "r");
    if (file == NULL) {
        perror("Error opening /etc/hostname");
        return 1;
    }
    printf("\nContents of /etc/hostname:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0;
}
