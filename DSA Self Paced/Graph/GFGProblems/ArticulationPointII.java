/**
 * @file ArticulationPointII.java
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 *        Articulation Point - II
 *        HardAccuracy: 62.77%Submissions: 4023Points: 8
 *        Given an undirected graph (not necessarily connected) with V vertices
 *        and adjacency list adj. You are required to find all the vertices
 *        removing which (and edges through it) disconnects the graph into 2 or
 *        more components, or in other words, removing which increases the
 *        number of connected components.
 *        Note: Indexing is zero-based i.e nodes numbering from (0 to V-1).
 *        There might be loops present in the graph.
 * 
 *        Example 1:
 * 
 *        Input:
 * 
 *        Output:{1,4}
 *        Explanation: Removing the vertex 1 will
 *        discconect the graph as-
 * 
 *        Removing the vertex 4 will disconnect the
 *        graph as-
 * 
 * 
 * 
 *        Your Task:
 *        You don't need to read or print anything. Your task is to complete the
 *        function articulationPoints() which takes V and adj as input
 *        parameters and returns a list containing all the vertices removing
 *        which turn the graph into two or more disconnected components in
 *        sorted order. If there are no such vertices then returns a list
 *        containing -1.
 * 
 * 
 *        Expected Time Complexity: O(V + E)
 *        Expected Auxiliary Space: O(V)
 * 
 * 
 *        Constraints:
 *        1 ≤ V ≤ 104
 * 
 * @version 0.1
 * @date 2022-12-02 08:15 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
import java.util.*;
// import java.lang.*;
import java.io.*;

class ArticulationPointII {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            int[] ans = obj.articulationPoints(V, adj);
            for (int i : ans)
                System.out.print(i + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends

class Solution {
    public void APDFS(
            ArrayList<ArrayList<Integer>> adj, int u, int parent[], boolean visited[],
            boolean isAP[], int low[], int disc[], int time) {
        int children = 0;

        low[u] = disc[u] = ++time;

        visited[u] = true;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                parent[v] = u;
                children++;

                APDFS(adj, v, parent, visited, isAP, low, disc, time);

                low[u] = Math.min(low[u], low[v]);

                if (parent[u] != -1 && low[v] >= disc[u])
                    isAP[u] = true;

            } else if (v != parent[u])
                low[u] = Math.min(low[u], disc[v]);

        }

        if (parent[u] == -1 && children >= 2)
            isAP[u] = true;
    }

    public int[] articulationPoints(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> temp = new ArrayList<>();

        boolean visited[] = new boolean[V];
        boolean isAP[] = new boolean[V];
        int parent[] = new int[V];

        int low[] = new int[V];
        int disc[] = new int[V];

        int time = 0;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            isAP[i] = false;
            parent[i] = -1;
            low[i] = 0;
            disc[i] = 0;
        }

        for (int i = 0; i < V; i++)
            if (!visited[i])
                APDFS(adj, i, parent, visited, isAP, low, disc, time);

        for (int k = 0; k < V; k++) {
            if (isAP[k] == true) {
                temp.add(k);
            }
        }

        if (temp.size() == 0) {
            int AP[] = new int[1];
            AP[0] = -1;
            return AP;

        }

        int AP[] = new int[temp.size()];
        for (int i = 0; i < temp.size(); i++)
            AP[i] = temp.get(i);

        return AP;
    }
}