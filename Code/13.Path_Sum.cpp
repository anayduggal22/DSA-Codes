// Path Sum in a Binary Tree

// Create a recursive function of bool type and which takes inputs as the root of tree, the target, and sum which is initialy 0.
// The function has 2 base cases, if root is NULL, return false and if root is leaf node and the sum is equal to target, return true.

// First add roots value to sum, then check the base cases, after base case call the same function but for left side, and store its output, if it is true, straight away return true, else just return the function call for right side of the node.

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
    bool path(TreeNode *root, int target, int sum)
    {

        // Base Case
        if (root == NULL)
        {
            return false;
        }

        // Add value to sum
        sum += root->val;

        if (root->left == NULL && root->right == NULL)
        {
            // When you are at leaf node, and sum is equal to target, return true
            if (sum == target)
            {
                return true;
            }
        }
        
        // Calculate sum for left, and also checking if sum = targetsum
        bool b = path(root->left, target, sum);

        if (b == true)
        {
            return true;
        }

        // Else do same for right
        return path(root->right, target, sum);
    }


    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // Create a function with one more input of sum
        return path(root, targetSum, 0);
    }
};

int main()
{
    Solution obj;

    // Creating tree:
    //        5
    //      /   \
    //     4     8
    //    /     / \
    //   11    13  4
    //  /  \        \
    // 7    2        1

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (obj.hasPathSum(root, targetSum))
    {
        cout << "Path exists with given sum";
    }
    else
    {
        cout << "Path does not exist";
    }

    return 0;
}
