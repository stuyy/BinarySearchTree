#include "tree.c"
#include <string.h>
#include <stdio.h>

char * copyString(char * str)
{
    char * copy = malloc(strlen(str)+1);
    strcpy(copy, str);
    return copy;
}

char * removeNewline(char * str)
{
    
}
int main(void)
{
    NODE * ROOT = NULL;
    printf("%s\n%s\n", "This is a Binary Search Tree Written in C.", "------------------------------------------");
    
    char * command = malloc(100);
    int flag = 1;
    while(flag)
    {
        printf("Command: ");
        fgets(command, 100, stdin);
        char * copy = copyString(command);
        char * token = strtok(copy, " ");
        if(strcmp(token, "ins") == 0)
        {
            int data = atoi(strtok(NULL, " "));
            insertTree(&ROOT, data);
            printf("Inserted %d\n", data);
        }
        else if(strcmp(token, "del") == 0)
        {
            
        }
        else if(strcmp(token, "in\n") == 0)
        {
            printInorder(&ROOT);
            printf("\n");
        }
        else if(strcmp(token, "pre\n") == 0)
        {
            printPreorder(&ROOT);
            printf("\n");
        }
        else if(strcmp(token, "post\n") == 0)
        {
            printPostorder(&ROOT);
            printf("\n");
        }
    }
    return 0;
}