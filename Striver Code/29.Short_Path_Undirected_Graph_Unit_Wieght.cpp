// Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.
// Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

// Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]

// Output: 0 1 2 1 2 3 3 4 4

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

// We create a distance array and set all distance to big value initially, then  set distance fo source to 0, then using bfs, we find all connected components of source check if thier distance is noted or not OR if the distance of source +1, is less than thier initial distance, we change thier distance and push it into the bfs queue

class Solution
{
public:

    void bfs(vector<vector<int>> &graph, vector<int>& distance, int source){

        queue<int> q;

        q.push(source);

        while(!q.empty()){
            
            int index = q.front();
            q.pop();

            for(int i = 0 ; i < graph[index].size() ; i++){
                
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
    {
        vector<int> distance(N,INT_MAX);

        vector<vector<int>> graph(N); // Adjacency List

        for(int i = 0 ; i < M ; i++){
            int r = edges[i][0];
            int c = edges[i][1];

            graph[r].push_back(c);
        }

        distance[0] = 0;

        bfs(graph,distance,0);

        return distance;
    }
};
