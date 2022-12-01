/**
 * @file KosarajuAlgorithm.java
 * @author ADITYA BHARDWAJ
 * @brief 
    Strongly Connected Components (Kosaraju's Algo)
MediumAccuracy: 50.61%Submissions: 50453Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.  

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:
Input:
5 5
1 0
0 2
2 1
0 3
3 4

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:
Input:
3 3
0 1
1 2
2 0

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106
 * @version 0.1
 * @date 2022-12-01 09:31 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
// import java.io.*;
// import java.lang.*;

class KosarajuAlgorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            // arraylist of arraylist to represent graph
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

            int V = Integer.parseInt(sc.next());
            int E = Integer.parseInt(sc.next());

            for (int i = 0; i < V; i++)
                adj.add(i, new ArrayList<Integer>());

            for (int i = 1; i <= E; i++) {
                int u = Integer.parseInt(sc.next());
                int v = Integer.parseInt(sc.next());

                // adding directed edgese between
                // vertex 'u' and 'v'
                adj.get(u).add(v);
            }

            Solution ob = new Solution();
            System.out.println(ob.kosaraju(V, adj));
        }
        sc.close();
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find number of strongly connected components in the graph.
    public void KDFS(ArrayList<ArrayList<Integer>> kadj, int source, boolean kvisited[]) {
        kvisited[source] = true;

        for (int v : kadj.get(source)) {
            if (!kvisited[v])
                KDFS(kadj, v, kvisited);
        }

    }

    public void DFSTopo(ArrayList<ArrayList<Integer>> adj, int source, Stack<Integer> s, boolean visited[]) {
        visited[source] = true;

        for (int v : adj.get(source)) {
            if (!visited[v])
                DFSTopo(adj, v, s, visited);
        }

        s.push(source);

    }

    public Stack<Integer> topologicalSort(ArrayList<ArrayList<Integer>> adj, int V) {
        boolean visited[] = new boolean[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                DFSTopo(adj, i, s, visited);

        return s;
    }

    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
        int count = 0;
        Stack<Integer> ks = topologicalSort(adj, V);

        // O(V+E)
        ArrayList<ArrayList<Integer>> kadj = new ArrayList<ArrayList<Integer>>(V);

        for (int i = 0; i < V; i++)
            kadj.add(new ArrayList<Integer>());

        for (int i = 0; i < V; i++) {
            for (int v : adj.get(i)) {
                kadj.get(v).add(i);
            }
        }

        // O(V+E)
        boolean kvisited[] = new boolean[V];

        for (int i = 0; i < V; i++)
            kvisited[i] = false;

        while (!ks.empty()) {
            int u = ks.peek();
            ks.pop();

            if (!kvisited[u]) {
                count++;
                KDFS(kadj, u, kvisited);
            }

        }

        return count;
    }
}
