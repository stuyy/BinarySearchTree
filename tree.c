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

// Inorder tree traversal. Prints Left, Root, Right.
void printInorder(NODE ** ROOT)
{
    if(*ROOT == NULL)
        return;
    
    printInorder(&(*ROOT)->leftChild);
    printf("%d ", (*ROOT)->data);
    printInorder(&(*ROOT)->rightChild);
    
}
// Preorder Tree Traversal. Prints Root, left, Right.
void printPreorder(NODE ** ROOT)
{
    if(*ROOT == NULL)
        return;

    printf("%d ", (*ROOT)->data);
    printPreorder(&(*ROOT)->leftChild);
    printPreorder(&(*ROOT)->rightChild);
    
}

// Postorder Tree Traversal. Prints Left, Right, Root.
void printPostorder(NODE ** ROOT)
{
    if(*ROOT == NULL)
        return;
    
    printPostorder(&(*ROOT)->leftChild);
    printPostorder(&(*ROOT)->rightChild);
    printf("%d ", (*ROOT)->data);
}

NODE * searchTree(NODE ** ROOT, int dataToFind)
{
    if(*ROOT == NULL)
        return NULL;
    
    if((*ROOT)->data == dataToFind)
        return *ROOT;
    else {
        // Check if the data to look for is in the left or right side of the BST.
        if(dataToFind < (*ROOT)->data)
            searchTree(&(*ROOT)->leftChild, dataToFind);
        else
            searchTree(&(*ROOT)->rightChild, dataToFind);
    }
}

// Function finds the minimum node of a Subtree.
NODE * findMinimumNode(NODE ** ROOT)
{
    NODE * tempNode = *ROOT;
    while(tempNode->leftChild != NULL)
        tempNode = tempNode->leftChild;
    
    return tempNode;
}

NODE * findParent()
{

}
void deleteNode(NODE ** ROOT, int data)
{
    NODE * nodeToDelete = searchTree(ROOT, data);
    if(nodeToDelete == NULL)
    {
        printf("Node was not found and could not delete from tree.\n");
        return;
    }
    else {
        // There are three cases for deleting a Node.
        // 1. Node we're deleting has no Children.
        // 2. Node we're deleting has 1 child.
        // 3. Node we're deleting has 2 children.
        if(data == (*ROOT)->data)
        {
            if((*ROOT)->leftChild == NULL && (*ROOT)->rightChild == NULL) // Case #1: Current Root of Subtree has NO Children.
            {
                free(*ROOT);
                return;
            }
            else if((*ROOT)->leftChild != NULL && (*ROOT)->rightChild == NULL) // Case #2: Left Child Exists, Right Child Does not.
            {
                // Since the left child exists, we need the parent of the child.
                NODE * temp = (*ROOT)->leftChild;
                (*ROOT) = temp;
                free((*ROOT)->leftChild);
                return;
            }
            else if((*ROOT)->rightChild != NULL && (*ROOT)->leftChild == NULL) // Case #2: Right Child Exists, Left Child Does not.
            {
                NODE * temp = (*ROOT)->rightChild; // Create a pointer to the current Root's Right Child.
                (*ROOT) = temp; // Set the current root to it's right child.
                free((*ROOT)->rightChild); // Free the right child from memory.
                return;
            }
            else { // Case #3: Two Children.

            }
        }
        else if(data < (*ROOT)->data)
        {
            if((*ROOT)->leftChild != NULL)
                deleteNode(&(*ROOT)->leftChild, data);
            else
                return;
        }
        else if(data > (*ROOT)->data)
        {
            if((*ROOT)->rightChild != NULL)
                deleteNode(&(*ROOT)->rightChild, data);
            else
                return;
        }
    }
}

int main(void)
{
    NODE * ROOT = NULL;
    insertTree(&ROOT, 10);
    insertTree(&ROOT, 15);
    insertTree(&ROOT, 7);
    insertTree(&ROOT, 5);
    insertTree(&ROOT, 9);
    insertTree(&ROOT, 6);
    insertTree(&ROOT, 4);
    insertTree(&ROOT, 2);
    printInorder(&ROOT);
    deleteNode(&ROOT, 4);
    printInorder(&ROOT);
    NODE * min = findMinimumNode(&ROOT);
    printf("Min: %d\n", min->data);
    return 0;
}