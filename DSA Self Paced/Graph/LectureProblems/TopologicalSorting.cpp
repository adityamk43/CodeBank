/**
 * @file TopologicalSorting.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * (Kahn's BFS Based Algortihm)
 * 
 * Topological Sorting for Jobs and their dependencies.
 * 
 * Topological Sorting is done on Directed Uncyclic Graph (DAG).
 * It uses BFS and maintains indegree array to ensure that jobs finishes first after then their dependencies
 * 
 * @version 0.1
 * @date 2022-11-28 01:22 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief TIME COMPLEXITY: O(V+E)
 * 
 * @param adj 
 * @param V 
 */
void topologicalSorting(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);

    for (int i=0; i<V;i++)
    {
        for (int x: adj[i])
            indegree[x]++;
        
    }
    queue<int> q;

    for (int i=0; i<V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v: adj[u])
        {
            indegree[v]--;
            
            if (indegree[v] == 0)
                q.push(v);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    // for (int i=0; i<V; i++)
    //     cout << indegree[i] << " ";
    // cout << endl;

    topologicalSorting(adj, V);

    return 0;
}