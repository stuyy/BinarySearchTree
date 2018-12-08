#include "tree.c"
#include <string.h>

int main(void)
{
    NODE * ROOT = NULL;
    printf("%s\n%s\n", "This is a Binary Search Tree Written in C.", "------------------------------------------");
    printf("Do you wish to proceed? Y/N\n");
    char choice = getchar();
    int flag = 1;
    char * cmd = malloc(64);
    if(choice == 'Y' || choice == 'y')
    {
        printf("OK.\n");
        while(flag)
        {
            printf("Enter a command or nothing to exit.\n");
            scanf("%s", cmd);
            if(strcmp(cmd, "exit") == 0)
                flag = 0;
            else {
                
            }
        }
    }
    
    return 0;
}