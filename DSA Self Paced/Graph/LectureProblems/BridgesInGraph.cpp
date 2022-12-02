/**
 * @file BridgesInGraph.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * An edge in an undirected connected graph is a bridge if and only if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar, a bridge is an edge removing which increases the number of disconnected components.

Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks. For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.

How to find all bridges in a given graph?

A simple approach is to one by one remove all edges and see if removal of an edge causes disconnected graph. Following are steps of a simple approach for a connected graph.
For every edge (u, v), do following
Remove (u, v) from graph.
See if the graph remains connected (We can either use BFS or DFS)
Add (u, v) back to the graph.
The time complexity of the above method is O(E*(V+E)) for a graph represented using adjacency list. Can we do better? A O(V+E) algorithm to find all Bridges is similar to that of O(V+E) algorithm for Articulation Points. We do DFS traversal of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v. As discussed in the previous post, the value low[v] indicates earliest visited vertex reachable from subtree rooted with v. The condition for an edge (u, v) to be a bridge is, "low[v] > disc[u]".
 * 
 * @version 0.1
 * @date 2022-12-02 06:33 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> myPair;

/**
 * @brief TIME COMPLEXITY: O(V+E) {As we are doing DFS with extra arrays and variables}
 * 
 * @param adj 
 * @param u 
 * @param visited 
 * @param isBridge 
 * @param parent 
 * @param low 
 * @param disc 
 * @param time 
 */
void bridgesDFS(vector<int> *adj, int u, vector<bool> &visited, vector<myPair> &isBridge, int parent, int low[], int disc[], int time)
{
    visited[u] = true;
    low[u] = disc[u] = ++time;

    for (int v: adj[u])
    {
        if (!visited[v])
        {
            bridgesDFS(adj, v, visited, isBridge, u, low, disc, time);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                isBridge.push_back(make_pair(u, v));

        }
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
            
    }

}

void bridges(vector<int> *adj, int V)
{
    vector<myPair> isBridge;
    vector<bool> visited(V, false);

    int low[V] = {0};
    int disc[V] = {0};
    int time = 0;
    int parent = -1;

    for (int i=0; i<V; i++)
    {
        if (!visited[i])
            bridgesDFS(adj, i, visited, isBridge, parent, low, disc, time);
    }

    for (int k=0; k<isBridge.size(); k++)
        cout << isBridge[k].first << " " << isBridge[k].second << endl;

}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    //EXAMPLE 1
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    //EXAMPLE 2
    // int V=4;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);

    //EXAMPLE 3
    // int V=7;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 1, 6);
    // addEdge(adj, 3, 5);
    // addEdge(adj, 4, 5);

    bridges(adj, V);

    return 0;
}
