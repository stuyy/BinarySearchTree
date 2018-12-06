#include <stdio.h>
#include <stdlib.h>
#include "node.c"

int isEmpty(NODE ** ROOT)
{
    if(*ROOT == NULL)
        return 1;
    else
        return 0;
}
void insertTree(NODE ** ROOT, int data)
{
    if(*ROOT == NULL)
        *ROOT = createNode(data);
    else {
        
    }
    
}

int main(void)
{
    NODE * ROOT = NULL;
    insertTree(&ROOT, 4);
    
    if(isEmpty(&ROOT))
        printf("The root is empty.\n");
    else {
        printf("The root is %d\n", ROOT->data);
    }
    return 0;
}