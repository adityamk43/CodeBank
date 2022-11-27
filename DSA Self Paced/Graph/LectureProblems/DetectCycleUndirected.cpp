/**
 * @file DetectCycleUndirected.cpp
 * @author ADITYA BHARDWAJ
 * @brief The apprach is that we will use DFS and maintain parent variable which will store parent vertex of the current vertex and if we reach a visited vertex that is not a parent of present vertex then it will form cycle
 * @version 0.1
 * @date 2022-11-27 07:44 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(V+E) Same as DFS as we are doing DFS
 * 
 * @param adj 
 * @param s 
 * @param visited 
 * @param parent 
 * @return true 
 * @return false 
 */
bool DFS(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (DFS(adj, u, visited, s) == true)
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }

    return false;
}

bool detectCycle(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (DFS(adj, i, visited, -1) == true)
                return true;
        }
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    //Cycle found
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    //No cycle found
    // int V = 4;
    // vector<int> adj[V];
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);

    if (detectCycle(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}