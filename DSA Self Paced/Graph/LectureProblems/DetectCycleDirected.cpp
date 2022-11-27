/**
 * @file DetectCycleDirected.cpp
 * @author ADITYA BHARDWAJ
 * @brief The approach is simple that we use DFS and rather like we did in Undirected one that is maintaining parent vertex, we will maintain recursion Stack array and if that vertex is still present in the recursion stack and we reach that vertex again during DFS then it will be called Cycle
 * @version 0.1
 * @date 2022-11-27 07:55 PM
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
bool DFS(vector<int> adj[], int s, bool visited[], bool recursionStack[])
{
    visited[s] = true;
    recursionStack[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (DFS(adj, u, visited, recursionStack) == true)
            {
                return true;
            }
        }
        else if (recursionStack[u] == true)
        {
            return true;
        }
    }

    recursionStack[s] = false;

    return false;
}

bool detectCycle(vector<int> adj[], int V)
{
    bool visited[V];
    bool recursionStack[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recursionStack[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && DFS(adj, i, visited, recursionStack) == true)
                return true;
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{

    //Cycle found
    int V = 6;
    vector<int> adj[V];
    addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

    if (detectCycle(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}