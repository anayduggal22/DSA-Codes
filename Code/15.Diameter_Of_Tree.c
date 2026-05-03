// Diameter of a Tree

#include <stdio.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int height(struct node *root, int *diameter)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    *diameter = max(*diameter, (lh + rh));

    return 1 + max(lh,rh);
    // 1 is for that node height contribution to the total height of that node.
}

int diameter_tree(struct node *root)
{
    int diameter = 0;
    // IMPORTANT
    height(root, &diameter);

    return diameter;
}

int main()
{

    return 0;
}