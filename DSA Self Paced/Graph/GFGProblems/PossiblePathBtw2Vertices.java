/**
 * @file PossiblePathBtw2Vertices.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * Possible paths between 2 vertices
MediumAccuracy: 56.57%Submissions: 19557Points: 4
Given a Directed Graph having V nodes numbered from 0 to V-1, and E directed edges. Given two nodes, source and destination, count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesn't contain multiple edges, self-loop, and cycles.


Example 1:

Input:
V = 5, E = 7
Edges of Graph = 
{0, 1}
{0, 2}
{0, 4}
{1, 3}
{1, 4}
{2, 4}
{3, 2}
source = 0 
destination = 4

Output: 4
Explanation: 

There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4

Example 2:

Input:
V = 4, E = 5
Edges of Graph = 
{0, 1}
{0, 3}
{1, 2}
{1, 3}
{2, 3}
source = 0 
destination = 3
Output: 3
Explanation:

There are 3 paths from 0 to 3.
0 -> 3
0 -> 1 -> 3
0 -> 1 -> 2 -> 3

Your task:
You don't need to read, input, or print anything. Your task is to complete the function countPaths(), which takes the integer V denoting the number of vertices, adjacency list adj, integer source, and destination as input parameters and returns the number of paths in the graph from the source vertex to the destination vertex.


Expected Time Complexity: O(V!)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 100
1 ≤ source, destination ≤ V


 * @version 0.1
 * @date 2022-12-02 08:10 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
// import java.lang.*;
import java.io.*;

class PossiblePathBtw2Vertices {
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
                // adj.get(v).add(u);
            }
            String[] S1 = br.readLine().trim().split(" ");
            int source = Integer.parseInt(S1[0]);
            int destination = Integer.parseInt(S1[1]);
            Solution obj = new Solution();
            System.out.println(obj.countPaths(V, adj, source, destination));
        }
    }
}

// } Driver Code Ends

class Count {

    public int c;

}

class Solution {
    // Function to count paths between two vertices in a directed graph.
    public void DFS(ArrayList<ArrayList<Integer>> adj, int source,
            int destination, boolean visited[], Count count) {
        visited[source] = true;

        if (source == destination)
            count.c++;

        for (int v : adj.get(source)) {
            if (!visited[v])
                DFS(adj, v, destination, visited, count);
        }

        visited[source] = false;

    }

    public int countPaths(int V, ArrayList<ArrayList<Integer>> adj, int source,
            int destination) {
        // Code here
        boolean visited[] = new boolean[V];
        Count count = new Count();

        DFS(adj, source, destination, visited, count);

        return count.c;
    }
}