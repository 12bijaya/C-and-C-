#include <stdio.h>
#include <string.h>

int main() {
    char name[10];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    int i = 0;
    while (name[i] != '\0') {
        printf("%c\n", name[i]);
        i++;
    }

    return 0;
}
