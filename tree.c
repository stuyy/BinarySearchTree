#include <stdio.h>
#include <stdlib.h>
#include "node.c"

void insertTree(NODE ** ROOT, int data)
{
    if(*ROOT == NULL)
    {
        printf("The Root is Null.\n");
    }
}

int main(void)
{
    NODE * ROOT = NULL;
    insertTree(&ROOT, 4);
    return 0;
}