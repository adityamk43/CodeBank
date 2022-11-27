/**
 * @file ShortestPathUnWeightedGraph.cpp
 * @author ADITYA BHARDWAJ
 * @brief We need to find the shortest path between source vertex to each vertex present in a unweighted graph
 * @version 0.1
 * @date 2022-11-27 07:30 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief TIME COMPLEXITY: O(V+E) same as BFS as we are doing BFS
 *
 * @param adj
 * @param V
 * @param dis
 */
void shortestPath(vector<int> adj[], int V, int s, int dis[])
{
    queue<int> q;
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    int dis[V];

    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    shortestPath(adj, V, 0, dis);

    for (int i = 0; i < V; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}