typedef struct node {
    int data;
    struct node * leftChild;
    struct node * rightChild;
} NODE;

NODE * createNode(int data)
{
    NODE * newNode = malloc(sizeof(NODE));
    newNode->data = data;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}
