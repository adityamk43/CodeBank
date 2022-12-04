/**
 * @file KruskalsAlgorithmGFG.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * EasyAccuracy: 53.28%Submissions: 1917Points: 2
You are given a graph where each edge has a weight associated with it.  Find the minimum spanning tree value.

Minimum Spanning Tree: Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together.  A single graph can have many different spanning trees.  A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

Example 1:

Input:
N = 5, M = 6
Edges[] = {(1,2,4),(1,3,3),(2,4,1),
           (2,5,1),(4,5,3),(3,4,2)}
Output: 7
Explanation: The tree will be formed from
these nodes and weights ,{1,3,3}, {2,4,1}
{2,5,1}, {3,4,2}. Total sum of these edges
is 7.
Example 2:

Input:
N = 4, M = 5
Edges[] = {(1,2,5),(2,3,6),(1,4,7),
           (2,4,8),(3,4,7)}
Output: 18
Explanation: The tree will be formed from
these nodes and weights, {1,2,5}, {2,3,6},
{3,4,7}. Total sum of those edges is 18
Your Task:

You will have to complete the function calcMinimumSpanningValue() function will return the minimum spanning value.

Note:
Cpp: The graph is given as array of vector containing pairs i.e. if adj[2] = (3,4) it implies src = 2, des = 3 wt = 4
Java: The graph is given as a Arraylist of a class Edge. Edge contains three variables- src, des, wt
Python: The graph is given by an array of triplets (src,des,wt)

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N + M).

Constraints:
2 <= N <= 105
1 <= M <= 105
1 <= node1, node2 <= N
1 <= edge weight <= 105
Graph doesn't contains multiple edges or self loops.
 *
 * @version 0.1
 * @date 2022-12-04 05:53 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
 */

// Function to find the minimum spanning tree value using Kruskal.
struct edge
{
    int u;
    int v;
    int wt;
    edge(int x, int y, int z)
    {
        u = x;
        v = y;
        wt = z;
    };
};

bool static comp(struct edge &x, struct edge &y)
{
    return x.wt < y.wt;
}

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
    {
        return i;
    }
    parent[i] = find(parent[i], parent);
    return parent[i];
}

void findunion(int a, int b, vector<int> &parent, vector<int> &rank)
{
    int a_rep = find(a, parent);
    int b_rep = find(b, parent);
    if (a_rep == b_rep)
    {
        return;
    }
    if (rank[a_rep] > rank[b_rep])
    {
        parent[b_rep] = a_rep;
    }
    else if (rank[a_rep] < rank[b_rep])
    {
        parent[a_rep] = b_rep;
    }
    else
    {
        parent[b_rep] = a_rep;
        rank[a_rep]++;
    }
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m)
{
    vector<edge> edges;
    for (int i = 1; i <= n; i++)
    {
        for (auto &e : adj[i])
        {
            int v = e.first;
            int w = e.second;
            if (v > i)
            {
                edge myEdge(i, v, w);
                edges.push_back(myEdge);
            }
        }
    }
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    long long ans = 0;
    for (auto &ed : edges)
    {
        int u = ed.u;
        int v = ed.v;
        int wt = ed.wt;
        if (find(u, parent) != find(v, parent))
        {
            findunion(u, v, parent, rank);
            ans += wt;
        }
    }
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    vector<pair<int, long long int>> adj[100009];

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int u, v;
        long long w;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        cout << kruskalDSU(adj, n, m) << endl;

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

// } Driver Code Ends