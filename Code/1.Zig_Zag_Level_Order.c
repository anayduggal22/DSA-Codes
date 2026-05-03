// Given the root of a binary tree, perform a zigzag (spiral) level order traversal.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *queue[130];
int f = -1;
int r = -1;

struct node *stack[130];
int top = -1;

int levelorder[130];
int l = 0;

int even = 0;

void zigzag_levelorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty");
        return;
    }

    queue[++r] = root; // PUSH

    while (f < r)
    {
        int size = r - f;

        // For each Level
        for (int i = 0; i < size; i++)
        {
            struct node *temp = queue[++f]; // POP

            if (even == 0) // L->R
            {
                levelorder[l++] = temp->data;
            }
            else if(even == 1) // R->L
            {
                stack[++top] = temp;
            }

            if (even == 0) // L->R
            {
                if (temp->left != NULL)
                {
                    queue[++r] = temp->left;
                }
                if (temp->right != NULL)
                {
                    queue[++r] = temp->right;
                }
            }
            else if (even == 1) // R->L
            {
                if (temp->right != NULL)
                {
                    queue[++r] = temp->right;
                }
                if (temp->left != NULL)
                {
                    queue[++r] = temp->left;
                }
            }
        }

        if (even == 1) // R->L
        {
            while (top != -1)
            {
                levelorder[l++] = stack[top--]->data;
            }
            even = 0;
        }
        else if (even == 0) // L->R
        {
            even = 1;
        }
    }

    

    for (int i = 0; i < l; i++)
    {
        printf("%d ", levelorder[i]);
    }
}

int main()
{
    return 0;
}