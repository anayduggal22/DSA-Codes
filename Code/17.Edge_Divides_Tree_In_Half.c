// Check if removing an edge can divide a Binary Tree in two halves

#include <stdio.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int TOTAL_NODES = 0;

// Counts the total number of nodes in the tree
int count_nodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Finds the size of each node and checks if it is half of the total nodes size.
int subtree_size(struct node *root)
{

    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int lh = subtree_size(root->left);
    
    if (lh == -1)
    {
        return -1;
    }

    int rh = subtree_size(root->right);
    if (rh == -1)
    {
        return -1;
    }

    int size = lh + rh + 1;

    if (size == TOTAL_NODES / 2)
    {
        return -1;
    }

    return size;
}

bool edge_dividing(struct node *root)
{
    TOTAL_NODES = count_nodes(root);

    if (TOTAL_NODES % 2 != 0)
    {
        return false;
    }

    if (subtree_size(root) == -1)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}