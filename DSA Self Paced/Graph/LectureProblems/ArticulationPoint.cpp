/**
 * @file ArticulationPoint.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * Articulation Points (or Cut Vertices) in a Graph
 * 
 * A vertex in an undirected connected graph is an articulation point (or cut vertex) if and only if removing it (and edges through it) disconnects the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more disconnected components(After finding this we can add extra vertices from ancestor to child of that vertex so that vertex can't be articulation point anymore!). They are useful for designing reliable networks.

For a disconnected undirected graph, an articulation point is a vertex removing which increases the number of connected components.

How to find all articulation points in a given graph?


A simple approach is to one by one remove all vertices and see if removal of a vertex causes disconnected graph. Following are steps of a simple approach for the connected graph.
For every vertex v, do following:
Remove v from graph
See if the graph remains connected (We can either use BFS or DFS)
Add v back to the graph
The time complexity of the above method is O(V*(V+E)) for a graph represented using adjacency list. Can we do better? A O(V+E) algorithm to find all Articulation Points (APs). The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex u is the parent of another vertex v, if v is discovered by u (obviously v is adjacent of u in the graph). In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
u is the root of DFS tree and it has at least two children.
u is not the root of DFS tree and it has a child v such that no vertex in the subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

We do DFS traversal of the given graph with additional code to find out Articulation Points (APs). In DFS traversal, we maintain a parent[] array where parent[u] stores parent of vertex u. Among the above mentioned two cases, the first case is simple to detect. For every vertex, count children. If currently visited vertex u is root (parent[u] is NIL) and has more than two children, print it. How to handle the second case? The second case is trickier. We maintain an array disc[] to store discovery time of vertices. For every node u, we need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we maintain an additional array low[] which is defined as follows.
low[u] = min(disc[u], disc[w]) 
where w is an ancestor of u and there is a back edge from 
some descendant of u to w.


 * @version 0.1
 * @date 2022-12-02 05:11 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(V+E) {As we are doing DFS with extra arrays and variables}
 * 
 * @param adj 
 * @param u 
 * @param visited 
 * @param isAP 
 * @param parent 
 * @param low 
 * @param disc 
 * @param time 
 */
void articulationPointDFS(vector<int> *adj, int u, vector<bool> &visited, vector<bool> &isAP, int parent, int low[], int disc[], int time)
{
    int children=0;

    visited[u] = true;
    low[u] = disc[u] = ++time;

    for (int v: adj[u])
    {
        if (!visited[v])
        {
            children++;

            articulationPointDFS(adj, v, visited, isAP, u, low, disc, time);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;

        }
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent == -1 && children >= 2)
        isAP[u] = true;

}

void articulationPoint(vector<int> *adj, int V)
{
    vector<bool> isAP(V, false);
    vector<bool> visited(V, false);

    int low[V] = {0};
    int disc[V] = {0};
    int time = 0;
    int parent = -1;

    for (int i=0; i<V; i++)
    {
        if (!visited[i])
            articulationPointDFS(adj, i, visited, isAP, parent, low, disc, time);
    }

    for (int k=0; k<V; k++)
        if (isAP[k] == true)
            cout << k << " ";
    cout << endl;

}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    //EXAMPLE 1
    // int V = 5;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);

    // //EXAMPLE 2
    // int V=5;
    // vector<int> adj[V];
    // addEdge(adj, 1, 0);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 2, 1);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 3, 4);

    // //EXAMPLE 3
    // int V=4;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);

    //EXAMPLE 4
    int V=7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 6);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    articulationPoint(adj, V);

    return 0;
}