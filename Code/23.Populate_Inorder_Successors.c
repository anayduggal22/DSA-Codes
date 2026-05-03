// Populate Inorder Successors

#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *arr[100];
int i = 0;

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        arr[i++] = root;
        inorder(root->right);
    }
}

void populateNext(struct node *root)
{
    inorder(root);

    if (i == 0)
    {
        return;
    }

    for (int j = 0; j < i - 1; j++)
    {
        arr[j]->next = arr[j + 1];
    }
    arr[i - 1]->next = NULL;
    
}

int main()
{

    return 0;
}