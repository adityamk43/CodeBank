/**
 * @file DetectCycleDSU.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Detect Cycle using DSU
EasyAccuracy: 35.86%Submissions: 6154Points: 2
Given an undirected graph with V nodes and E edges. The task is to check if there is any cycle in undirected graph.
Note: Solve the problem using disjoint set union(dsu).


Example 1:

Input:

Output: 1
Explanation: There is a cycle between 0->2->4->0
Example 2:

Input:

Output: 0
Explanation: The graph doesn't contain any cycle


Your Task:
You don't need to read or print anyhting. Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list denoting as adj and returns 1 if graph contains any cycle otherwise returns 0.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


Constraints:
1 ≤ V, E ≤ 104

 * @version 0.1
 * @date 2022-12-04 05:54 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct DisjointSets
{
    int n;
    int *parent;
    int *ranks;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n];
        ranks = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);

        return parent[u];
    }

    void union_merge(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);

        if (x_rep == y_rep)
            return;

        if (ranks[x_rep] < ranks[y_rep])
            parent[x_rep] = y_rep;
        else if (ranks[x_rep] > ranks[y_rep])
            parent[y_rep] = x_rep;

        else
        {
            parent[y_rep] = x_rep;
            ranks[x_rep]++;
        }
    }
};

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        DisjointSets ds(V);

        for (int i = 0; i < V; i++)
        {
            for (int v : adj[i])
            {
                int u = i;

                int u_rep = ds.find(u);
                int v_rep = ds.find(v);

                if (u_rep == v_rep && v > i)
                    return 1;
                else
                    ds.union_merge(u, v);
            }
        }

        return 0;
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
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends