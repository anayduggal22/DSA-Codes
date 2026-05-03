// Binary Tree Level Order

// Create a queue and store the root in it, now using a loop which terminates when queue become empty, and a nested loop which runs queue size times which was already calculated before the loop runs, pop the queue into a temporary tree node, store the left and right of that node in the queue if it exists, and store the temporary queues value in a vector.
// After the termination of the inner loop push the vector into a 2-D vector to show the levels, repeat it till the queue becomes emty, which at that point return the 2-D level order vector.

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> level_order;

        // Acting like a queue
        vector<TreeNode *> q;

        if (root == NULL)
        {
            return level_order;
        }

        q.push_back(root);
        // Actiong like front of queue
        int front = 0;

        while (front < q.size()) // While queue is not empty
        {

            int size = q.size() - front;
            vector<int> levels;

            // For each level
            for (int i = 0; i < size; i++)
            {
                // Poping the front node
                TreeNode *temp = q[front];
                front++;

                // Pushing this levels value in an array
                levels.push_back(temp->val);
                
                if (temp->left != NULL)
                {
                    // Pushing for next level
                    q.push_back(temp->left);
                }

                if (temp->right != NULL)
                {
                    // Pushing for next level
                    q.push_back(temp->right);
                }

            }

            // Pushing the whole level ordered array
            level_order.push_back(levels);
        }
        
        return level_order;
    }
};

int main()
{
    Solution obj;

    // Creating tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // Level Order Traversal:
    // 1
    // 2 3
    // 4 5 6 7

    return 0;
}
