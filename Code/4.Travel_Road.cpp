/*
Very Easy Brute Force Logic (Multi-Source Dijkstra):

1. First, we find which village numbers are prime.
   These villages already have vaccine, so their distance = 0.

2. Then we create a graph using adjacency list.
   Time to travel between two villages = max(u, v).

3. We make a distance array and visited array.

4. Now we apply very simple brute force Dijkstra:
   Each time we pick the unvisited village with smallest time
   and update its neighboring villages.

5. At the end, distance array will store minimum time
   for vaccine to reach each village.

Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check prime
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int N = 6; // number of villages

    vector<vector<int>> roads = {
        {1,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,6}
    };

    // Make adjacency list
    vector<vector<pair<int,int>>> adj(N+1);

    for (int i = 0; i < roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];

        int time = max(u, v);

        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    // Distance and visited array
    vector<int> dist(N+1, 1000000);
    vector<int> visited(N+1, 0);

    // Multi-source: Prime villages start with distance 0
    for (int i = 1; i <= N; i++) {
        if (isPrime(i)) {
            dist[i] = 0;
        }
    }

    // Brute force Dijkstra
    for (int i = 1; i <= N; i++) {

        int minDist = 1000000;
        int node = -1;

        // Find minimum distance village
        for (int j = 1; j <= N; j++) {
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
            int time = adj[node][j].second;

            if (dist[node] + time < dist[next]) {
                dist[next] = dist[node] + time;
            }
        }
    }

    // Print answer
    cout << "Minimum time for vaccine to reach each village:\n";

    for (int i = 1; i <= N; i++) {
        cout << "Village " << i << " -> " << dist[i] << endl;
    }

    return 0;
}