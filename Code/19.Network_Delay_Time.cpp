/*
Approach (Very Simple):

1. Store the graph using adjacency list.
2. Make distance array and visited array.
3. Set starting node distance = 0.
4. Find unvisited node with smallest distance.
5. Update distance of its neighbors.
6. Repeat for all nodes.
7. Find maximum distance from distance array.
8. If any node not reachable, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Create adjacency list
        vector<vector<pair<int,int>>> adj(n+1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        // Distance and visited array
        vector<int> dist(n+1, 1000000);
        vector<int> visited(n+1, 0);

        dist[k] = 0;

        // Brute force Dijkstra
        for (int i = 1; i <= n; i++) {

            int minDist = 1000000;
            int node = -1;

            // Find minimum distance node
            for (int j = 1; j <= n; j++) {
                if (visited[j] == 0 && dist[j] < minDist) {
                    minDist = dist[j];
                    node = j;
                }
            }

            if (node == -1)
                break;

            visited[node] = 1;

            // Update neighbors
            for (int j = 0; j < adj[node].size(); j++) {
                int next = adj[node][j].first;
                int weight = adj[node][j].second;

                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                }
            }
        }

        // Find maximum distance
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1000000) {
                return -1;
            }

            if (dist[i] > ans) {
                ans = dist[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;

    int result = obj.networkDelayTime(times, n, k);

    cout << result;

    return 0;
}