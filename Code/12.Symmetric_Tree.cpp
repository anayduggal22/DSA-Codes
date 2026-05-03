// To check if Trees are symmetric

// Create a function which takes the left and right half of the tree, now using recursion go left of left side and right of right side recursively till either both reach NULL at the same time, at which return true, of if one of them reach NULL or if there value are not equal, at which return false, if it is false, straight away return false, else if it is true, do the same thing but now go right of left side and left of right side and check the same thing, if this side is true, return true, else return false.

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool order(TreeNode *l, TreeNode *r)
    {

        // Base Cases
        if (l == NULL && r == NULL)
        {
            return true;
        }

        // Base Cases
        else if ((l != NULL && r == NULL) 
              || (l == NULL && r != NULL))
        {
            return false;
        }

        // Base Cases
        if (l->val != r->val)
        {
            return false;
        }

        bool b;

        if (l->left != NULL && r->right != NULL)
        {

            b = order(l->left, r->right);

            if (b == false)
            {
                return false;
            }
        }

        // Previous BASE CASE checking but now for left and right
        else if ((l->left != NULL && r->right == NULL) 
              || (l->left == NULL && r->right != NULL))
        {
            return false;
        }


        return order(l->right, r->left);
    }


    bool isSymmetric(TreeNode *root)
    {
        return order(root->left, root->right);

    }
};

int main()
{
    Solution obj;

    // Creating a symmetric tree:
    //        1
    //      /   \
    //     2     2
    //    / \   / \
    //   3   4 4   3

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (obj.isSymmetric(root))
    {
        cout << "Tree is symmetric";
    }
    else
    {
        cout << "Tree is not symmetric";
    }

    return 0;
}
