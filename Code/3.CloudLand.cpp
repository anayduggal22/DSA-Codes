// Cloudland Cities Reach Problem

/*
Very Easy Brute Force Logic:

1. Store the cities and roads in a graph.
2. Keep an array to store minimum fuel needed to reach each city.
3. Start from the starting city.
4. Each time, pick the city with smallest distance.
5. Update the distance of its neighboring cities.
6. After finding all shortest distances, count how many cities
   can be reached with given fuel.
7. Print the count.

This is brute force Dijkstra because we use simple loops
to find the minimum distance city.
Time Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;     // number of cities
    int fuel = 5;  // fuel available
    int start = 0; // starting city

    // Roads: {city1, city2, fuel cost}
    vector<vector<int>> roads = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 3},
        {2, 4, 2},
        {3, 4, 1}};

    // Make adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance array (store minimum fuel to reach each city)
    vector<int> dist(n, 1000000);
    vector<int> visited(n, 0);

    dist[start] = 0;

    // Brute force Dijkstra
    for (int i = 0; i < n; i++)
    {

        // Find minimum distance city
        int minDist = 1000000;
        int node = -1;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < minDist)
            {
                minDist = dist[j];
                node = j;
            }
        }

        if (node == -1)
        {
            break;
        }

        visited[node] = 1;

        // Update neighbors
        for (int j = 0; j < adj[node].size(); j++)
        {
            int next = adj[node][j].first;
            int cost = adj[node][j].second;

            if (dist[node] + cost < dist[next])
            {
                dist[next] = dist[node] + cost;
            }
        }
    }

    // Count cities reachable within fuel
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] <= fuel)
        {
            count++;
        }
    }

    cout << "Cities Alice can reach: " << count;

    return 0;
}