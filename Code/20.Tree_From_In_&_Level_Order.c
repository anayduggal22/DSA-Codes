// Construct Tree from Inorder and Level Order

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Creation of a new node
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Finds position of a value in inorder
int search(int arr[], int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

// end is always size of array - 1
struct node *build(int inorder[], int level[], int start, int end, int n)
{

    // Base case
    if (start > end)
    {
        return NULL;
    }

    // In level order first element is always root
    // 20
    struct node *root = newNode(level[0]);

    // If only one node exists
    if (start == end)
    {
        return root;
    }

    // Finding root in inorder
    int index = search(inorder, start, end, level[0]);

    // Level arrays for left and right subtree
    int left[100], right[100];
    int l = 0, r = 0;

    // Separating nodes for left and right subtree
    // leftLevel  = 8 4 12 10 14
    // rightLevel = 22

    for (int i = 1; i < n; i++) // IMP Start from 1
    {
        int pos = search(inorder, start, end, level[i]);

        if (pos < index)
        {
            left[l++] = level[i];
        }
        else if (pos > index)
        {
            right[r++] = level[i];
        }
    }

    // Recursively build left and right subtree
    root->left = build(inorder, left, start, index - 1, l); // leftLevel  = 8 4 12 10 14
    root->right = build(inorder, right, index + 1, end, r); // rightLevel = 22

    return root;
}

int main()
{

    int inorder[] = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};

    int n = 7;

    struct node *root = build(inorder, level, 0, n - 1, n);

    return 0;
}