/**
 * @file BFSDisconnectedGraph.cpp
 * @author ADITYA BHARDWAJ
 * @brief No source is given with a Disconnected Graph.
 * 
 * FEW APPLICATIONS OF BFS:
 * 
 * 1.) Shortest Path in an unweighted Graph.
 * 2.) Crawlers in Search Engines.
 * 3.) Peer to Peer Networks.
 * 4.) Social Networking Search
 * 5.) In Garbage Collection (Cheney's Algorithm)
 * 6.) Cycle Detection
 * 7.) Ford Fulkerson Algorithm (can also be done by DFS but BFS is more optimised)
 * 8.) Broadcasting
 * 
 * NOTE: Many other algorithms also uses BFS like Dijsktra, Prims etc.
 * @version 0.1
 * @date 2022-11-26 10:37 PM
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
 * @param visited 
 * @param s 
 */

void BFS(vector<int> adj[], bool visited[], int s)
{
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int x: adj[v])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
}

void BFSDis(vector<int> adj[], int V)
{
    bool visited[V];

    for (int i=0; i<V; i++)
        visited[i] = false;

    for (int i=0; i<V; i++)
    {
        if (visited[i] == false)
            BFS(adj, visited, i);
        
    }
}


void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{

    int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

    cout << "BFS:" << endl;
    BFSDis(adj, V);

    return 0;
}