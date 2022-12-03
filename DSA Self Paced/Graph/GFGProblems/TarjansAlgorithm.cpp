/**
 * @file TarjansAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Strongly connected component (Tarjans's Algo)
HardAccuracy: 36.78%Submissions: 16011Points: 8
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.


Example 1:

Input:
5 5
1 0
0 2
2 1
0 3
3 4

Output:
0 1 2,3,4,
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph as mentioned
in the Output.

Example 2:
3 3
0 1
1 2
2 0

Input:

Output:
0 1 2,
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC as shown.

Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
1 ≤ V  ≤ 105
1 ≤ E  ≤ 105
0 ≤ u, v ≤ N-1
 * @version 0.1
 * @date 2022-12-03 03:44 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    void tarjansDFS(vector<int> adj[], int u, vector<bool> &stackMember, vector<int> &low, vector<int> &disc, vector<vector<int>> &vect, stack<int> &st)
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

    vector<vector<int>> tarjans(int V, vector<int> adj[])
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

        sort(vect.begin(), vect.end());

        return vect;
    }
};

//{ Driver Code Starts.

int main()
{

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
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                if (j == ptr[i].size() - 1)
                    cout << ptr[i][j];
                else
                    cout << ptr[i][j] << " ";
            }
            cout << ',';
        }
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends