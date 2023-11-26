#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    int frequency;
    struct node *left;
    struct node *right;
};
