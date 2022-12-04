/**
 * @file NumberofConnectedComponents.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Number of Connected Components
EasyAccuracy: 50.24%Submissions: 3160Points: 2
This problem is to find the number of connected components. There will be 2 incomplete functions namely unionNodes and findNumberOfConnectedNodes. You have to complete these functions.

unionNodes: Join two subsets into a single set.
findNumberOfConnectedNodes: Determine number of different connected components in a graph.

Example 1:

Input:
N = 5
M = 2
Edges[] = {(1,3),(1,5)}
Output: 3
Explanation: Initially all nodes 1 2 3 4 5
are not connected.
After 1 3, node 1 and 3 will be connected.
After 1 5, node 1 and 5 will be connected.
Finally we have {1,3,5}, {2}, {4}. So we
have a total of 3 connected components.
Example 2:

Input:
N = 5
M = 4
Edges[] = {(1,4),(2,3),(1,5)}
Output: 2
Explanation: Initially all nodes 1 2 3 4 5
are not connected.
After 1 4, node 1 and 4 will be connected.
After 2 3, node 2 and 3 will be connected.
After 1 5, node 1 and 5 will be connected.
Finally we have {1,4,5}, {2, 3}. So we
have total of 2 connected components
Your Task:

You have to complete the function unionNodes() which merges the node1 and node2. You will also have to complete the function findNumberOfConnectedNodes() function will returntotal number of different connected components in a graph.

Note: We recommend you to solve this problem first https://practice.geeksforgeeks.org/problems/union-find/1. There are ways to solve this problem from BFS and DFS as well. But for this problem stick to filling these functions as in union-find.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 105
1 <= M <= 105
1 <= node1, node2 <= N

 * @version 0.1
 * @date 2022-12-04 05:55 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to merge two nodes a and b.
    int find(int x, int par[])
    {
        if (x != par[x])
            par[x] = find(par[x], par);

        return par[x];
    }

    void unionNodes(int a, int b, int par[], int rank1[], int n)
    {
        // code here
        int a_rep = find(a, par);
        int b_rep = find(b, par);

        if (a_rep == b_rep)
            return;

        if (rank1[a_rep] < rank1[b_rep])
            par[a_rep] = b_rep;
        else if (rank1[b_rep] < rank1[a_rep])
            par[b_rep] = a_rep;

        else
        {
            par[b_rep] = a_rep;
            rank1[a_rep]++;
        }
    }

    // Function to determine number of connected components.
    int findNumberOfConnectedComponents(int n, int par[], int rank1[])
    {
        // code here
        //  set<int> s;
        //  int count = 0;

        // for (int i=1; i<=n; i++)
        // {
        //     s.insert(par[i]);
        // }

        // return s.size();

        // OR

        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == i)
                count++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        // taking number of nodes
        int n;
        cin >> n;

        // initializing parent array and
        // rank array
        for (int i = 1; i <= n; i++)
        {
            arr[i] = i;
            rank1[i] = 1;
        }

        // taking number of queries
        int q;
        cin >> q;
        Solution obj;
        while (q--)
        {
            int a, b;
            cin >> a >> b;

            // calling unionNodes() function
            obj.unionNodes(a, b, arr, rank1, n);
        }

        // calling function findNumberofConnectedComponents()
        cout << obj.findNumberOfConnectedComponents(n, arr, rank1) << endl;
    }
    return 0;
}
// } Driver Code Ends