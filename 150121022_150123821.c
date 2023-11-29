#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    int frequency;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key, int frequency)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
};

struct node *insert(struct node *root, int key, int frequency){
if (root == NULL)
    {
        return newNode(key, frequency);
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

void search(struct node *root, int key){
if(key == root->key){
    root->frequency++;
}
else if(key < root->key){
    search(root->right, key);
}
else if(key > root->key){
    search(root->left, key);
}
};

int main(){
FILE *fptr;
int key, frequency, searchvalue;
struct node *root = NULL;

fptr = fopen("input.txt", "r");
while(fscanf(fptr, "%d", &key) == 1)
{
  root = insert(root, key, 0);
}
fclose(fptr);
printf("%d %d", root->key, root->frequency);

printf("Enter a value to search: ");
scanf("%d", &searchvalue);
search(root, searchvalue);
printf("%d %d", root->key, root->frequency);

return 0;
}

