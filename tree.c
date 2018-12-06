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
// insertTree takes in a Double Pointer, which is the address of the pointer to the Root Node.
// it takes in an integer, which will resemble the data we're trying to insert into the Tree.
void insertTree(NODE ** ROOT, int data)
{
    if(*ROOT == NULL) // Dereference the double pointer, to reference the address of the ROOT Node. 
        *ROOT = createNode(data);
    else if((*ROOT)->data == data)
        return;
    else {
        // Check if the data needs to go to the left or the right.
        // If the data to add is less than the data to the left, then we need to recursively call insertTree, passing it the leftChild of the current Node.
        if(data < (*ROOT)->data) 
        {
            // Check if the left Child is NULL.
            if((*ROOT)->leftChild == NULL)
                (*ROOT)->leftChild = createNode(data);
            else
                insertTree(&(*ROOT)->leftChild, data); // Pass in the address to the leftChild of the NODE Pointer.
        }
        else if(data > (*ROOT)->data)
        {
            if((*ROOT)->rightChild == NULL)
                (*ROOT)->rightChild = createNode(data);
            else
                insertTree(&(*ROOT)->rightChild, data);
        }
    }
}

void printInOrder(NODE ** ROOT)
{
    if(*ROOT == NULL)
        return;
    
    printInOrder(&(*ROOT)->leftChild);
    printf("%d ", (*ROOT)->data);
    printInOrder(&(*ROOT)->rightChild);
}
int main(void)
{
    NODE * ROOT = NULL;
    insertTree(&ROOT, 4);
    insertTree(&ROOT, 2);
    insertTree(&ROOT, 6);

    if(isEmpty(&ROOT))
        printf("The root is empty.\n");
    else {
        printf("The root is %d\n", ROOT->data);
        printf("The root's left is %d\n", ROOT->leftChild->data);
        printf("The root's right is %d\n", ROOT->rightChild->data);
    }

    printInOrder(&ROOT);
    return 0;
}