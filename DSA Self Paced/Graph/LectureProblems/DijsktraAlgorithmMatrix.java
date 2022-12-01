
/**
 * @file DijsktraAlgorithmMatrix.java
 * @author ADITYA BHARDWAJ
 * @brief We have seen that adjacency list and min heap provides opitmised version of Dijsktra's Algo but let's see Dijsktra's Algo for adjacency Matrix.
 *
 * It works similary like Prim's Algorithm but here we do relax operation:
 *        if (dist[v] > dist[u] + weight) -> dist[v] = dist[u] + weight
 *
 * Some Interesting Facts about Dijsktra's Algorithm:
 *
 * 1.) It doesn't work for negative weight edges
 * eg: graph.addEdge(0, 1, 4);
 *     graph.addEdge(0, 2, 8);
 *     graph.addEdge(1, 2, -10);
 *
 * output that will come through this algo will be:
 *   vertex: 0  1  2
 *    dist:  0  4  -6
 *
 * But originally, we should have got:
 *  vertex:  0  1  2
 *    dist:  0  4 -2
 *
 * So, as we can see from example Dijsktra's Algorithm gives wrong output for negative weight edges.
 * So, this algorithm doesn't work for negative weight edges!!
 *
 *
 * 2.) Does the shortest path change if we add certain same weight to all edges of a original graph?
 *      Yes
 *      But the same is not true if we multiple weight as it will count as a factor which by default will get cancelled as they are common factors. But if we add or subtract certain weight then it can change the shortest path.
 *
 * How this works? Well, when we add or subtract then the factor which works here is the number of edges in different paths. The path with minimum number of edges may become shortest path after additon/subtraction of certain weights.
 *
 * eg:              (11)
 *              1 -------- 2
 *      (10)  /             \ (12)
 *          0                3
 *      (17) \             /
 *            4 ---------- (18)
 *
 *  Shortest path here is: 10 + 11 + 12 = 33
 *  Other path has total weight as: 17 + 18 = 35
 *
 * Suppose, if we add 10 to all edges then,
 * 1st Path: 20 + 21 + 22 = 63
 * 2nd Path: 27 + 28 = 55
 *
 * So, as we can see now 2nd Path is the shortest Path!!
 *
 *
 * @version 0.1
 * @date 2022-12-01 05:48 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

import java.util.*;
// import java.lang.*;
// import java.io.*;

class DijsktraAlgorithmMatrix {

    static final int V = 4;

    public static int[] djikstra(int graph[][], int src) {

        int[] dist = new int[V];
        // int res = 0;
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] fin = new boolean[V];

        for (int count = 0; count < V - 1; count++) {
            int u = -1;

            for (int i = 0; i < V; i++)
                if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            fin[u] = true;

            for (int v = 0; v < V; v++)

                if (graph[u][v] != 0 && fin[v] == false)
                    dist[v] = Math.min(dist[v], dist[u] + graph[u][v]);
        }
        return dist;
    }

    public static void main(String[] args) {
        int graph[][] = new int[][] { { 0, 50, 100, 0 },
                { 50, 0, 30, 200 },
                { 100, 30, 0, 20 },
                { 0, 200, 20, 0 }, };

        for (int x : djikstra(graph, 0)) {
            System.out.print(x + " ");
        }

    }
}