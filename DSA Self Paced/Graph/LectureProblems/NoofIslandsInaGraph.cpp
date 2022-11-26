/**
 * @file NoofIslandsInaGraph.cpp
 * @author ADITYA BHARDWAJ
 * @brief We have to find total number of cyclic graphs in a disconnected graph
 *  (or number of connected components in a graph)
 * @version 0.1
 * @date 2022-11-26 10:45 PM
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

int BFSDis(vector<int> adj[], int V)
{
    int count=0;
    bool visited[V];

    for (int i=0; i<V; i++)
        visited[i] = false;

    for (int i=0; i<V; i++)
    {
        if (visited[i] == false)
        {
            count++;
            BFS(adj, visited, i);
        }
        
    }

    return count;
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

    cout << "Number of Islands in this Disconnected Graph is/are:" << endl;
    cout << BFSDis(adj, V) << endl;

    return 0;
}