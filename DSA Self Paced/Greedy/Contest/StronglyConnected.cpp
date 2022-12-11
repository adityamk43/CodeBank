/**
 * @file StronglyConnected.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * You have a directed graph having V nodes and E edges. From all the possible strongly connected components formed, print the size of one which contains maximum number of nodes in it.
 *
 * INPUT:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case, contains two space seperated integers, corresponding to V and E, as the number of nodes in the graph and number of edges present respectively. E lines corresponding to edges follow. Every edge is described by 2 integers, u , v corresponding to a directed edge from u to v.

OUTPUT:
Print the size of the largest strongly connected component in the graph.

CONSTRAINTS:
2 <= V <=1000
0 <= E <= 1000

EXAMPLE:
I/P:
2
5 7
1 2
2 1
1 3
2 3
3 4
4 5
5 3
2 1
1 2

O/P:
3
1
 *
 *
 * @version 0.1
 * @date 2022-12-11 04:51 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

void tarjansDFS(vector<int> adj[], int u, vector<bool> &stackMember, vector<int> &low,
                vector<int> &disc, vector<vector<int>> &vect, stack<int> &st)
{
    static int ttime = 0;

    stackMember[u] = true;

    low[u] = disc[u] = ++ttime;

    st.push(u);

    for (int v : adj[u])
    {
        if (disc[v] == -1)
        {
            tarjansDFS(adj, v, stackMember, low, disc, vect, st);

            low[u] = min(low[u], low[v]);
        }

        else if (stackMember[v] == true)
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        vector<int> myVect;

        while (st.top() != u)
        {
            int k = st.top();
            myVect.push_back(k);

            stackMember[k] = false;
            st.pop();
        }

        //This condition check is not important or required
        if (!st.empty())
        {
            int k = st.top();
            myVect.push_back(k);
            stackMember[k] = false;
            st.pop();
        }

        sort(myVect.begin(), myVect.end());

        vect.push_back(myVect);
    }
}

int tarjans(int V, vector<int> adj[])
{
    // code here
    vector<vector<int>> vect;

    vector<bool> stackMember(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            tarjansDFS(adj, i, stackMember, low, disc, vect, st);
        }
    }

    // sort(vect.begin(), vect.end());
    int res = 1;

    for (int z = 0; z < vect.size(); z++)
    {
        if (vect[z].size() > res)
            res = vect[z].size();
    }

    return res;
}

int main()
{
    // code
    int t;
    cin >> t;

    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
        }

        cout << tarjans(V, adj);

        cout << endl;
    }

    return 0;
}