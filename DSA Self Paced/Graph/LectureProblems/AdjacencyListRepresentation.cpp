/**
 * @file AdjacencyListRepresentation.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * DISADVANTAGE OF ADJACENCY MATRIX IS THAT IT STORES REDUNDANT INFORMATION OF VERTICES THAT ARE NOT CONNECTED IN THE FORM OF 0.
 *
 * Adjacency List solve this problem!!
 *
 * An Array of lists where list are most popularly represented as:
 *      (a) Dynamic Sized Arrays
 *      (b) Linked Lists
 * (NOTE: Dynamic Sized Arrays are most popularly used for adjacency list representation. It has advantage of cache friendliness over linked lists but it may also have some disadvantage that it preallocates extra space and when space is filled then it creates new doubled sized space and copy the values from old array which can take O(v) time)
 *
 *
 *
 * PROPERTIES OF ADJACENCY LIST:
 *
 * Space Required: ⊝(V + E)
 *                  Undirected: V + 2*E
 *                  Directed: V + E
 *
 * Operations:
 *      Check if there is an edge from u to v: O(V)
 *      Find all adjacent of u: ⊝(degree(u))
 *      Find degree of u: ⊝(1)
 *      Add an Edge: ⊝(1) [For Linked List: always ⊝(1) and for dynamic sized during reallocation in double sized one it can be O(v)]
 *      Remove an Edge: O(v)
 *      Add/Remove a Vertex: Much Less than ⊝(v^2) (Adding and removing vertex is rarely done but adjacency list is also better in these operations as compared to adjacency matrix)
 *
 *  Example:
 * 0: 1->2
 * 1: 0->2
 * 2: 0->1->3
 * 3: 2
 *     1
 *   / |
 *  0  |  3
 *   \ | /
 *     2
 * 
 * IMPORTANT NOTE: SO OVERALL AND IN GENERAL ADJACENCY LIST IS MORE OPTIMISED THAN ADJACENCT MATRIX. 
 * 
 * Undirected: 0 <= E <= (V*(V-1))/2
 * Directed: 0 <= E <= V*(V-1)
 * 
 * SPARSE GRAPH: Like road connections, network router connections, social media networks where E cannot be close to V*(V-1) are called SPARSE GRAPH.
 * 
 * DENSE GRAPH: Graph in which edges are close to V*(V-1) are called DENSE GRAPH.
 * 
 * Since, finding adjacent vertex is most used operations in many algorithms like DFS, BFS, Prims, Dijkstra and Adjacency is more optimised in this, So Adjacency List is more preferred for these algorithms!!
 * 
 * For Example: IN BFS/DFS: Time Complexity for Adjacency List: O(V+E)
 *                          Time Complexity for Adjacecny Matrix: O(V^2)
 *
 * @version 0.1
 * @date 2022-11-26 02:54 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
}

// Driver code
int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, V);
    return 0;
}