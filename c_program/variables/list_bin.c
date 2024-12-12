#include <stdio.h>//including header hile which contains the function like: scanf(), printf(), getch() and so on
#include <stdlib.h>
void list_bin()
{
    system("ls /bin > Output.txt");
    printf("Contents of /bin directory have been stored in Output.txt\n");
}
int main(){
    list_bin();
    return 0;
}
