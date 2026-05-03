// Reverse Level Order Traversal


#include <stdio.h>
#include <limits.h>

struct node *queue[130];
int f = -1;
int r = -1;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};



void reverse_level(struct node *root)
{
    if(root == NULL){
        return;
    }                   
    
    queue[++r] = root;
    int array[130];
    int j = 0;

    while (f < r)
    {
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

        // Done to add level separation
        array[j++] = INT_MIN;
        array[j++] = INT_MIN;
    }


    // Reversing the array using two pointers
    int i = 0; 
    int k = j -1;
    while(i < k ){
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
        i++;
        k--;
    }

    for(int i = 0 ; i < j ; i++){
        if(array[i] == INT_MIN){
            i++;
            printf("\n");
            continue;
        }
        printf("%d ",array[i]);
    }
}

int main()
{

    return 0;
}