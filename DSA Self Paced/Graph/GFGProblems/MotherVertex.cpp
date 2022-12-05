/**
 * @file MotherVertex.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Mother Vertex
EasyAccuracy: 47.64%Submissions: 25663Points: 2
Given a Directed Graph, find a Mother Vertex in the Graph (if present).
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.


Example 1:

Input:
5 5
1 0
0 2
2 1
2 3
3 4
Output: 0
Explanation: According to the given edges, all
nodes can be reaced from nodes from 0, 1 and 2.
But, since 0 is minimum among 0,1 and 3, so 0
is the output.
Example 2:

Input:
3 2
0 1
2 1

Output: -1
Explanation: According to the given edges,
no vertices are there from where we can
reach all vertices. So, output is -1.


Your Task:
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as imput parameter and returns the verticex from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then returns the node with minimum value.If not possible returns -1.


Expected Time Complexity: O(V + E)
Expected Space Compelxity: O(V)


Constraints:
1 ≤ V ≤ 500
 *
 * @version 0.1
 * @date 2022-12-05 07:17 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find a Mother Vertex in the Graph.
    void DFS(vector<int> adj[], int s, vector<bool> &visited)
    {
        visited[s] = true;

        for (int v : adj[s])
        {
            if (!visited[v])
                DFS(adj, v, visited);
        }
    }

    int findMotherVertex(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        int v = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(adj, i, visited);
                v = i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        DFS(adj, v, visited);

        for (int i = 0; i < V; i++)
            if (!visited[i])
                return -1;

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        int ans = obj.findMotherVertex(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends