// Clone Graph [ DFS ]

// Create a visited vector which stores the address of the cloned node corresponding
// to each original node value.
// Then create a DFS function which takes the original node and the visited vector.
// If the node is NULL, return NULL.
// If the node is already visited (i.e., cloned node already exists in visited),
// then return the cloned node.
// Otherwise, create a new node with the same value and store it in visited.
// Then traverse all the neighbors of the original node and call DFS on each neighbor,
// and push those cloned neighbors into the neighbors list of the cloned node.
// At the end, return the cloned node.
// The main function calls the DFS function and returns the cloned graph.

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int val) {
        val = val;
    }
};

class Solution {
public:

    Node* dfs(Node* node, vector<Node*>& visited) {
        if (node == NULL) {
            return NULL;
        }

        // If already cloned, return it
        if (visited[node->val] != NULL) {
            return visited[node->val];
        }

        // Create clone node
        Node* cloned_node = new Node(node->val);
        visited[node->val] = cloned_node;

        // Clone neighbors
        for (int i = 0; i < node->neighbors.size(); i++) {
            cloned_node->neighbors.push_back(dfs(node->neighbors[i], visited));
        }

        return cloned_node;
    }

    Node* cloneGraph(Node* node) {

        vector<Node*> visited(130, NULL);
        
        return dfs(node, visited);
    }
};