#include "tree.c"

int main(void)
{
    NODE * ROOT = NULL;
    insertTree(&ROOT, 35);
    insertTree(&ROOT, 17);
    insertTree(&ROOT, 45);
    insertTree(&ROOT, 37);
    deleteNode(&ROOT, 37);
    printInorder(&ROOT);
    int num = nodeCount(&ROOT);
    printf("The total number of nodes: %d\n", num);
    return 0;
}