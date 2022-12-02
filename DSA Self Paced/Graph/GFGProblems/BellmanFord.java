/**
 * @file BellmanFord.java
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 *        Distance from the Source (Bellman-Ford Algorithm)
 *        MediumAccuracy: 48.11%Submissions: 26457Points: 4
 *        Given a weighted, directed and connected graph of V vertices and E
 *        edges, Find the shortest distance of all the vertex's from the source
 *        vertex S.
 *        Note: If the Graph contains a negative cycle then return an array
 *        consisting of only -1.
 * 
 *        Example 1:
 * 
 *        Input:
 * 
 *        E = [[0,1,9]]
 *        S = 0
 *        Output:
 *        0 9
 *        Explanation:
 *        Shortest distance of all nodes from
 *        source is printed.
 *        Example 2:
 * 
 *        Input:
 * 
 *        E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
 *        S = 2
 *        Output:
 *        1 6 0
 *        Explanation:
 *        For nodes 2 to 0, we can follow the path-
 *        2-0. This has a distance of 1.
 *        For nodes 2 to 1, we cam follow the path-
 *        2-0-1, which has a distance of 1+5 = 6,
 * 
 * 
 *        Your Task:
 *        You don't need to read input or print anything. Your task is to
 *        complete the function bellman_ford( ) which takes a number of vertices
 *        V and an E-sized list of lists of three integers where the three
 *        integers are u,v, and w; denoting there's an edge from u to v, which
 *        has a weight of w and source node S as input parameters and returns a
 *        list of integers where the ith integer denotes the distance of an ith
 *        node from the source node.
 * 
 *        If some node isn't possible to visit, then its distance should be
 *        100000000(1e8). Also, If the Graph contains a negative cycle then
 *        return an array consisting of only -1.
 * 
 * 
 * 
 *        Expected Time Complexity: O(V*E).
 *        Expected Auxiliary Space: O(V).
 * 
 * 
 * 
 *        Constraints:
 *        1 ≤ V ≤ 500
 *        1 ≤ E ≤ V*(V-1)
 *        -1000 ≤ adj[i][j] ≤ 1000
 *        0 ≤ S < V
 * 
 * @version 0.1
 * @date 2022-12-02 04:35 PM
 * 
 * @copyright Copyright (c) 2022
 */

//{ Driver Code Starts
import java.util.*;
import java.io.*;
// import java.lang.*;

class DriverClass {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);

            ArrayList<ArrayList<Integer>> edges = new ArrayList<>();

            int i = 0;
            while (i++ < E) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                ArrayList<Integer> t1 = new ArrayList<>();
                t1.add(u);
                t1.add(v);
                t1.add(w);
                edges.add(t1);
            }

            int S = Integer.parseInt(read.readLine());

            // Solution ob = new Solution();

            int[] ptr = Solution.bellman_ford(V, edges, S);

            for (i = 0; i < ptr.length; i++)
                System.out.print(ptr[i] + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends

// User function Template for Java

/*
 * edges: vector of vectors which represents the graph
 * S: source vertex to start traversing graph with
 * V: number of vertices
 */
class Solution {
    static int[] bellman_ford(int V, ArrayList<ArrayList<Integer>> edges, int S) {
        // Write your code here
        int dist[] = new int[V];

        for (int i = 0; i < V; i++)
            dist[i] = 100000000;

        dist[S] = 0;

        for (int count = 0; count < V - 1; count++) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges.get(i).get(0);
                int v = edges.get(i).get(1);
                int weight = edges.get(i).get(2);

                if (dist[u] != 100000000 && dist[v] > dist[u] + weight)
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges.get(i).get(0);
            int v = edges.get(i).get(1);
            int weight = edges.get(i).get(2);

            if (dist[u] != 100000000 && dist[v] > dist[u] + weight) {
                int res[] = new int[1];
                res[0] = -1;
                return res;
            }
        }

        return dist;

    }
}
