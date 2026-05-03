// All the Possible Binary Trees with given Inorder

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function that generates all possible binary trees
// start and end represent the current range of inorder
void build(int inorder[], int start, int end)
{
    // Base case
    if (start > end)
    {
        printf("NULL ");
        return;
    }

    // Trying every element as root
    for (int i = start; i <= end; i++)
    {

        // Current element becomes root
        printf("Root = %d\n", inorder[i]);

        // Elements before root in inorder become left subtree
        printf("Left subtree: ");
        build(inorder, start, i - 1);

        // Elements after root in inorder become right subtree
        printf("\nRight subtree: ");
        build(inorder, i + 1, end);

        // Space between different trees
        printf("\n\n");
    }
}

int main()
{

    // Given inorder traversal
    int inorder[] = {1, 2, 3};

    int n = 3;

    // Calling the function to generate trees
    build(inorder, 0, n - 1);

    return 0;
}