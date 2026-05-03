// Complete Binary Tree from Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct treenode *queue[130];
int f = -1;
int r = -1;


struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *create_node(int data)
{
    struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


struct treenode *list_to_complete_binary(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct treenode *root = create_node(head->data); // Root of the tree
    struct node *temp = head->next; // List Pointer, initially at head's next.

    queue[++r] = root; // Push the root

    while (temp != NULL) // Traverses the whole list
    {
        struct treenode *t = queue[++f]; // POPs

        // Create left side of tree
        t->left = create_node(temp->data);
        queue[++r] = t->left;  // PUSHES LEFT HALF

        // If the list has only one element left done go right.
        if (temp->next != NULL)
        {
            temp = temp->next;
            t->right = create_node(temp->data);
            queue[++r] = t->right;  // PUSHES RIGHT HALF
        }

        temp = temp->next;
    }

    return root;
}

int main()
{

    return 0;
}