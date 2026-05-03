// Print Binary Tree levels in sorted order

#include <stdio.h>

struct node *queue[130];
int f = -1;
int r = -1;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void print_sorted(int *array, int size)
{
    if (size == 1)
    {
        printf("%d \n", array[0]);
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sorted_level(struct node *root)
{
    if(root == NULL){
        return;
    }
    
    queue[++r] = root;
    while (f < r)
    {
        int array[130];
        int j = 0;
        int size = r - f;
        for (int i = 0; i < size; i++)
        {
            struct node *temp = queue[++f];
            array[j++] = temp->data;

            if (temp->left != NULL)
            {
                queue[++r] = temp->left;
            }
            if (temp->right != NULL)
            {
                queue[++r] = temp->right;
            }
        }

        print_sorted(array, j);                                                            
    }
}

int main()
{

    return 0;
}