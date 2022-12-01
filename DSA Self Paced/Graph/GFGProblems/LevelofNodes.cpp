/**
 * @file LevelofNodes.cpp
 * @author ADITYA BHARDWAJ
 * @brief SAME AS SHORTEST PATH FOR UNDIRECTED UNWEIGHTED GRAPH (SEE IN LECTURE PROBLEMS) BUT TWISTED
 *
 * Level of Nodes
MediumAccuracy: 50.95%Submissions: 14498Points: 4
Given a Undirected Graph with V vertices and E edges, Find the level of node X. if X does not exist in the graph then print -1.
Note: Traverse the graph starting from vertex 0.


Example 1:

Input:
6 5
0 1
0 2
1 3
1 4
2 5
4
X = 4
Output:
2
Explanation:

We can clearly see that Node 4 lies at Level 2.
Example 2:

Input:
4 3
0 1
0 2
0 3
5
X = 5
Output:
-1
Explanation:
Node 5 isn't present in the Graph, so the
Output is -1.


Your task:
You dont need to read input or print anything. Your task is to complete the function nodeLevel() which takes two integers V and X denoting the number of vertices and the node, and another adjacency list adj as input parameters and returns the level of Node X. If node X isn't present it returns -1.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)



Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
0 ≤ u, v < V
1 ≤ X ≤ 104
Graph doesn't contain multiple edges and self loops.
 *
 * @version 0.1
 * @date 2022-12-01 09:34 PM
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
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // code here
        queue<int> q;

        vector<bool> visited(V, false);
        vector<int> dist(V, -1);
        dist[0] = 0;

        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == X)
                return dist[u];

            for (int v : adj[u])
            {
                if (visited[v] == false)
                {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // for (int i=0; i<V; i++)
        // {
        //     if (i == X)
        //         return dist[i];
        // }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E, X;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> X;

        Solution obj;
        cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

// } Driver Code Ends