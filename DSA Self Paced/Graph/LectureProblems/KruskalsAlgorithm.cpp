/**
 * @file KruskalsAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * NOTE: To understand Kruskal Algorithm properly, see Disjoint Set Data Structures Implementation first!!
 * 
 * What is Minimum Spanning Tree?


Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, and undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

Number of edges in a minimum spanning tree: A minimum spanning tree has (V – 1) edges, where V is the number of vertices in the given graph.

Algorithm: The Kruskal's algorithm for finding MST works on a Greedy method:

1.) Sort all the edges of the given graph in increasing order according to their weight.
2.) Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge, else discard it.
3.) Repeat step 2 until there are (V-1) edges in the spanning tree.


NOTE: In Step 2 to check whether adding an edge forms a cycle or not efficiently, Union-Find algorithm is used. (Disjoint Set Data Structure is used) 
 * 
 * @version 0.1
 * @date 2022-12-04 03:43
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSets
{
    int n;
    int *parent;
    int *ranks;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n];
        ranks = new int[n];

        for (int i=0; i<n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        
        return parent[u];
    }

    void union_merge(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        
        if (x_rep == y_rep)
            return;

        if (ranks[x_rep] < ranks[y_rep])
            parent[x_rep] = y_rep;
        else if (ranks[x_rep] > ranks[y_rep])
            parent[y_rep] = x_rep;
        
        else
        {
            parent[y_rep] = x_rep;
            ranks[x_rep]++;
        }
    }
};

struct Edge
{
    int src, dest, wt;

    Edge(){};

    Edge(int s, int d, int w)
    {
        this->src = s;
        this->dest = d;
        this->wt = w;
    }

};

bool myCmp(Edge e1, Edge e2)
{
    //for increasing/ascending order
    return e1.wt < e2.wt;
}


class Graph
{
    int V;
    int E;
    int eindex;
    Edge *edges;

    public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        this->eindex = 0;

        edges = new Edge[E];
    }
    
    void addEdge(int u, int v, int w)
    {
        if (eindex >=0 && eindex<E)
        {
            edges[eindex].src = u;
            edges[eindex].dest = v;
            edges[eindex].wt = w;
            eindex++;
        }
    }

    /**
     * @brief TIME COMPLEXITY: O(ElogE + V + E*α(V))
     * 
     * => O(ElogE)
     * => O(ElogV) Since, E is V in Undirected Graph.
     * 
     * Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is the same as O(LogE). Therefore, the overall time complexity is O(ElogE) or O(ElogV).
     * 
     * NOTE: For more understanding Time Complexity again check below function's comments for each statements individually.
     * 
     * @return int 
     */
    int kruskalAlgo()
    {
        int total_wt=0;
        //O(ElogE)
        sort(edges, edges+E, myCmp);

        //O(V) to initialise ranks and parents array in disjoint sets
        DisjointSets ds(V);

        //O(E * α(V)) -> O(E)
        //In worst case whole edges will be traversed if we doesn't find disjoint(different subsets vertices) and all vertices, so it will take maximum linear time of E to traverse here where E is the total number of edges
        //As we have discussed in Disjoint Sets Implementation, it takes amortised Time for find() and union() functions, and since we have used union by rank and path compression together, so, it will take amortised constant time here for find() and union() function.
        for (int i=0, s=0; s<V-1; i++)
        {
            Edge e = edges[i];
            int u = e.src;
            int v = e.dest;
            int weight = e.wt;

            int u_rep = ds.find(u);
            int v_rep = ds.find(v);

            if (u_rep != v_rep)
            {
                cout << u << "-" << v << " weight:" << weight << endl;
                total_wt += weight;
                ds.union_merge(u, v);
                s++;
            }
        }

        return total_wt;

    }

    //Function to check if edges are inserted correctly or not!
    void printEdges()
    {
        // sort(edges, edges+E, myCmp);
        for (int i=0; i<E; i++)
        {
            cout << edges[i].src << "->" << edges[i].dest << " weight:" << edges[i].wt;
            cout <<endl; 
        }
    }

};


int main()
{
    Graph graph(5, 7);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 4);
    graph.addEdge(2, 4, 12);
    graph.addEdge(3, 4, 15);

    //Function to check if edges are inserted correctly or not!
    // graph.printEdges();

    graph.kruskalAlgo();
    
    return 0;
}