/**
 * @file KruskalsAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief Minimum Spanning Tree using Kruskal
EasyAccuracy: 53.28%Submissions: 1917Points: 2
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

 * @version 0.1
 * @date 2022-12-04 05:53
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
typedef pair<int, long long int> myPair;

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

struct Edge
{
    int src, dest;
    long long int wt;

    Edge(){};

    Edge(int s, int d, long long int w)
    {
        this->src = s;
        this->dest = d;
        this->wt = w;
    }
};

bool myCmp(Edge e1, Edge e2)
{
    // for increasing/ascending order
    return e1.wt < e2.wt;
}

// Function to find the minimum spanning tree value using Kruskal.
long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m)
{
    Edge *edges = new Edge[m];
    int eindex = 0;

    for (int i = 0; i < n; i++)
    {
        for (myPair mp : adj[i])
        {
            int u = i;
            int v = mp.first;
            int weight = mp.second;

            if (v > i)
            {
                edges[eindex].src = u;
                edges[eindex].dest = v;
                edges[eindex].wt = weight;
                eindex++;
            }
        }
    }

    sort(edges, edges + m, myCmp);

    DisjointSets ds(n);
    long long int total_weight = 0;

    for (int i = 0, s = 0; s < n - 1; i++)
    {
        Edge e = edges[i];
        int u = e.src;
        int v = e.dest;
        int weight = e.wt;

        int u_rep = ds.find(u);
        int v_rep = ds.find(v);

        if (u_rep != v_rep)
        {
            total_weight += weight;
            ds.union_merge(u, v);
            s++;
        }
    }

    // for (int i=0; i<m; i++)
    // {
    //     cout << edges[i].src << "->" << edges[i].dest << " weight:" << edges[i].wt;
    //     cout <<endl;
    // }

    // return 0;
    return total_weight;
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