#include <stdio.h>
#include <stdlib.h>

/*** OFFLINE VERSION OF THE PROGRAM ***/

/* LINKED LIST PART */
// Firstly, we used linked list in order to store frequency values descending order.
typedef struct tempNode{
    int key;
    int frequency;
    struct tempNode* next;
} tempNode;

// Declare global HEAD tempNode variable which is head of linked list.
tempNode* HEAD = NULL;

// Create linked list node using createTempNode function.
tempNode* createTempNode(int key, int frequency){
    tempNode* newNode = (tempNode*)malloc(sizeof(tempNode));
    newNode->frequency = frequency;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Add linked list nodes by descending order.
void addNodeBySequence(int key, int frequency){
    tempNode * newNode = createTempNode(key,frequency);
    if(HEAD == NULL){
        HEAD = newNode;
    }
    // Add linked list node at begin.
    if(HEAD->frequency < newNode->frequency){
        newNode->next = HEAD;
        HEAD = newNode;
    }
    else{
        // Declare temporary current variable to traverse the linked list.
        tempNode* current = HEAD;
        while(current->next!=NULL){
            if(current->frequency > newNode->frequency && current->next->frequency < newNode->frequency){
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            else {
                current = current->next;
            }
        }
        // Add linked list node at end.
        if(current->frequency > newNode->frequency && current->next == NULL){
            // Declare temporary current variable to traverse the linked list.
            tempNode* current = HEAD;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

/* END OF LINKED LIST PART */

/* BINARY SEARCH TREE PART */
// Struct of node of BST containing key value, frequency value and children pointers.
typedef struct node
{
    int key;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

// Create BST node using createNode function.
Node *createNode(int key, int frequency)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
};

// Insert nodes to BST by not violating BST rules recursively.
Node *insert(Node *root, int key, int frequency){
    Node* newNode = createNode(key,frequency);
    if (root == NULL) root = newNode;
    else if (key < root->key)
    {
        root->left = insert(root->left, key, frequency);
    }
    else
    {
        root->right = insert(root->right, key, frequency);
    }
    return root;
};

// Print nodes according to preorder traversal of the tree recursively.
void preorderTraversal(Node* root){
    if(root==NULL) return;
    printf("%d ",root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Declare argc and argv for command line arguments.
// For instance, >prj1.exe input.txt
// prj1.exe is argv[0], input.txt is argv[1]
// argc is the number of command line arguments.
int main(int argc, char* argv[]){

    // Declare fptr FILE pointer variable to open txt file
    FILE *fptr = fopen(argv[argc-1], "r");

    // Declare key and frequency variable to extract key and frequency values from txt file.
    int key, frequency;

    // Initialize root of BST
    Node* root = NULL;

    // FILE HANDLING //
    if(fptr == NULL) printf("The file does not exist!!!");

    // Extracting key and frequency values using fscanf and store them into linked list which head is HEAD variable initialized start of the LL part.
    else{
        while(fscanf(fptr,"%d, %d", &key, &frequency) == 2){
            addNodeBySequence(key,frequency);
        }
    }
    fclose(fptr);

    // Traverse in the linked list to construct BST
    while(HEAD->next != NULL){
        root = insert(root,HEAD->key,HEAD->frequency);
        HEAD = HEAD->next;
    }
    root = insert(root,HEAD->key,HEAD->frequency);

    // Print preorder traversal of constructed tree
    printf("Pre-order traversal of constructed tree: ");
    preorderTraversal(root);
    return 0;
}


