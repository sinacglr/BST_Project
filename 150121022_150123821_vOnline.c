#include <stdio.h>
#include <stdlib.h>

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
    node->left = NULL;
    node->right = NULL;
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
    printf("(%d,%d), ",root->key,root->frequency);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void searchInTree(Node* root,int num){
    if(root == NULL){
        printf("The number %d not contained in the tree...\n",num);
        return;
    }
    else if(root->key == num){
        root->frequency++;
    }
    else if(root->key > num){
        searchInTree(root->left,num);
    }
    else{
        searchInTree(root->right,num);
    }
}

Node* rotation(Node *root){
    if(root == NULL){
        return root;
    }
    if(root->left != NULL && root->left->frequency > root->frequency){
        Node* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root = temp;
        return root;
    }
    else if(root->right != NULL && root->right->frequency > root->frequency){
        Node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root = temp;
        return root;
    }
    if(root->left != NULL && root->frequency == root->left->frequency){
        rotation(root->left);
    }
    if(root->right != NULL && root->frequency == root->right->frequency){
        rotation(root->right);
    }
    return root;
}

int main(int argc, char* argv[]){
    FILE *fptr = fopen(argv[argc-1],"r");
    int key;
    Node* root = NULL;
    if(fptr == NULL) printf("The file does not exist!!!");
    else{
        while(fscanf(fptr,"%d",&key) == 1){
            root = insert(root,key,0);
        }
    }
    fclose(fptr);
    while(1==1){
        printf("Pre-order traversal of constructed tree: ");
        preorderTraversal(root);
        printf("\n");
        printf("Enter a value to search: ");
        scanf("%d",&key);
        searchInTree(root,key);
        root = rotation(root);
    }

}
