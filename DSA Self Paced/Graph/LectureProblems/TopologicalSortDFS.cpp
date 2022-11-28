/**
 * @file TopologicalSortDFS.cpp
 * @author ADITYA BHARDWAJ
 * @brief We have seen previously the Kahn's Algorithm for Topological Sorting which uses BFS.
 * Here we will use DFS in a way that its algorithm will remain very close to DFS of undirected graph. The only modification is that we will maintain a stack which will push dependencies and then its descendant i.e. their descendant jobs.
 * @version 0.1
 * @date 2022-11-28 11:40 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], int s, vector<bool> &visited, stack<int> &st)
{
    visited[s] = true;

    for (int v: adj[s])
    {
        if (visited[v] == false)
            DFS(adj, v, visited, st);
    }

    st.push(s);

}

/**
 * @brief TIME COMPLEXITY : O(V+E)
 *  
 *  (V+E) -> DFS
 *  V -> stack traversal
 * 
 * So, Overall O(V+V+E) -> O(2V+E) => O(V+E)
 * @param adj 
 * @param V 
 */
void topologicalSortDFS(vector<int> adj[], int V)
{
    stack<int> s;
    vector<bool> visited(V, false);

    for (int i=0; i<V; i++)
    {
        if (visited[i] == false)
            DFS(adj, i, visited, s);
    }

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        cout << u << " ";
    }

}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Following is a Topological Sort of\n";
    topologicalSortDFS(adj, V);

    return 0;
}