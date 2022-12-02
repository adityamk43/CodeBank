
/**
 * @file BridgesinGraph.java
 * @author ADITYA BHARDWAJ
 * @brief
 *        Bridge edge in a graph
 *        MediumAccuracy: 34.61%Submissions: 31630Points: 4
 *        Given a Graph of V vertices and E edges and another edge(c - d), the
 *        task is to find if the given edge is a Bridge. i.e., removing the edge
 *        disconnects the graph.
 * 
 * 
 * 
 *        Example 1:
 * 
 *        Input:
 *          5 5
            1 0
            1 2
            2 0
            0 3
            3 4
            2 0
 *        c = 1, d = 2
 *        Output:
 *        1
 *        Explanation:
 *        From the graph, we can clearly see that
 *        blocking the edge 1-2 will result in
 *        disconnection of the graph. So, it is
 *        a Bridge and thus the Output 1.
 * 
 *        Example 2:
 * 
 *        Input:
 *          1 0
 *          1 2
 *          2 0
 *          0 3
 *          3 4
 *          0 2
 * 
 *        c = 0, d = 2
 *        Output:
 *        0
 *        Explanation:
 * 
 *        blocking the edge between nodes 0 and 2
 *        won't affect the connectivity of the graph.
 *        So, it's not a Bridge Edge. All the Bridge
 *        Edges in the graph are marked with a blue
 *        line in the above image.
 * 
 * 
 *        Your Task:
 *        You don't need to read input or print anything. Your task is to
 *        complete the function isBridge() which takes number of vertices V, the
 *        number of edges E, an adjacency lsit adj and two integers c and d
 *        denoting the edge as input parameters and returns 1 if the given edge
 *        c-d is a Bridge. Else, it returns 0.
 * 
 * 
 * 
 *        Expected Time Complexity: O(V + E).
 *        Expected Auxiliary Space: O(V).
 * 
 * 
 * 
 *        Constraints:
 *        1 ≤ V,E ≤ 105
 *        0 ≤ c, d ≤ V-1
 * 
 * @version 0.1
 * @date 2022-12-02 08:11 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//{ Driver Code Starts
import java.util.*;
// import java.io.*;
// import java.lang.*;

class BridgesinGraph {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V + 1; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int c = sc.nextInt();
            int d = sc.nextInt();

            // Solution ob = new Solution();

            System.out.println(Solution.isBridge(V, list, c, d));
        }

        sc.close();
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find if the given edge is a bridge in graph.
    static boolean bridgeDFS(
            ArrayList<ArrayList<Integer>> adj, int u, int parent[], boolean visited[],
            int low[], int disc[], int time, int c, int d) {
        low[u] = disc[u] = ++time;

        visited[u] = true;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                parent[v] = u;

                if (bridgeDFS(adj, v, parent, visited, low, disc, time, c, d) == true)
                    return true;

                low[u] = Math.min(low[u], low[v]);

                if (low[v] > disc[u] && ((c == u && d == v) || (c == v && d == u)))
                    return true;

            } else if (v != parent[u])
                low[u] = Math.min(low[u], disc[v]);
        }

        return false;
    }

    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj, int c, int d) {
        // code here
        int parent[] = new int[V];
        boolean visited[] = new boolean[V];
        int low[] = new int[V];
        int disc[] = new int[V];
        int time = 0;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            parent[i] = -1;
            low[i] = disc[i] = 0;
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bridgeDFS(adj, i, parent, visited, low, disc, time, c, d) == true)
                    return 1;
            }
        }

        return 0;
    }
}