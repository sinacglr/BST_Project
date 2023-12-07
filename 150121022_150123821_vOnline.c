#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int key, int frequency)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
};

Node *insert(Node *root, int key, int frequency){
if (root == NULL)
    {
        return createNode(key, frequency);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key, frequency);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key, frequency);
    }
    return root;
};

void search(Node *root, int key){

if(root == NULL){
    return;
}
if(key == root->key){
    root->frequency++;
}

if(key < root->key){
    search(root->left, key);
}
else{
    search(root->right, key);
}
};

void rotation(Node *root){
Node* temp = NULL;
if(root->left != NULL && root->left->frequency > root->frequency){
    rightRotation(root);
}

else if(root->left != NULL && root->right->frequency > root->frequency){
    leftRotation(root);
}
};

void rightRotation(Node* root){
    if(root == NULL){
        return;
    }
    root = root->left;
    root->right=root;
    rightRotation(root->left);
};

void leftRotation(Node* root){
    if(root == NULL){
        return;
    }
    root = root->right;
    root->left=root;
    leftRotation(root->right);
};



void preorderTraversal(Node* root){
    if(root==NULL) return;
    printf("(%d,",root->key);
    printf("%d),", root->frequency);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};


int main(){
FILE *fptr;
int key, frequency, searchvalue;
Node *root = NULL;

fptr = fopen("input2.txt", "r");
while(fscanf(fptr, "%d", &key) == 1)
{
  root = insert(root, key, 0);
}
fclose(fptr);

printf("Pre-order traversal of constructed tree: ");
preorderTraversal(root);
printf("\n");

while(1){
printf("\nEnter a value to search: ");
scanf("%d", &searchvalue);
search(root, searchvalue);
rotation(root);
printf("Pre-order traversal of constructed tree: ");
preorderTraversal(root);
printf("\n");
}
return 0;
}
