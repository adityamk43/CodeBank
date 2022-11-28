/**
 * @file DetectCycleDirected_2.cpp
 * @author ADITYA BHARDWAJ
 * @brief We can use Kahn's Algorithm that we used for topological sorting for detecting cycle in a Directed Graph.
 * 
 * We know that Kahn's Algorithm only works for Directed Uncyclic Graph but we can modify it in a way so that we can use it to find the cycle in a directed graph.
 * 
 * @version 0.1
 * @date 2022-11-28 02:19 PM
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
bool detectCycle(vector<int> adj[], int V)
{
    int count = 0;
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

        for (int v: adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }

        //count to increment number of vertex reached using topological sorting
        count++;
    }

    return (count != V);
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    // int V=5;
    // vector<int> adj[V];
    // addEdge(adj, 0, 2);
    // // addEdge(adj, 0, 3);
    // addEdge(adj, 3, 0);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);

    int V=5;
    vector<int> adj[V];
    addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);

    if (detectCycle(adj, V) == true)
        cout << "Cycle is found" << endl;
    else
        cout << "Cycle not found" << endl;

    return 0;
}