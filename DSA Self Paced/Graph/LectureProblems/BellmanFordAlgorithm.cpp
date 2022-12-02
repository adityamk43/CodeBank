/**
 * @file BellmanFordAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * Bellman Ford Algorithm uses Dynamic Programming approach i.e. in a bottom up manner. It first finds all edges in a graph with weight 1, then all edges with weight 2 and so on..
 * 
 * Algroithm: We Relax edges V-1 Times.
 * 
 * BellmanFord Algorithm can also be used to find whether there is an negative edge in a graph or not.
 * 
 * Although it has higher time complexity than dijsktra but it can solve the problem if a graph has negative edges which dijsktra couldn't solve.
 * 
 * We have discussed Dijkstra's algorithm for this problem. Dijkstra's algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn't work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.
 * 
 * How does this work? Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest distances which have at most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| - 1 edge in any simple path, that is why the outer loop runs |v| - 1 time. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edge.
 * 
 * 
 * Important Notes:
    1.) Negative weights are found in various applications of graphs. For example, instead of paying the cost for a path, we may get some advantage if we follow the path.
    
    2.) Bellman-Ford works better (better than Dijkstra's) for distributed systems. Unlike Dijksra's where we need to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one.

 * @version 0.1
 * @date 2022-12-02 02:32 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> myPair;

class Edge
{
    public:
    int src;
    int dest;
    int weight;

    Edge()
    {
        this->src = 0;
        this->dest = 0;
        this->weight = 0;
    }

    Edge(int src, int dest, int weight)
    {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }

};

class Graph
{
    int V;
    int E;
    Edge *edge;
    int index;
    
    public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        this->index = 0;
        edge = new Edge[E];
    }

    void addEdge(int u, int v, int weight)
    {
        edge[index].src = u;
        edge[index].dest = v;
        edge[index].weight = weight;
        ++index;
    }

    void printEdge()
    {
        for (int i=0; i<E; i++)
        {
            cout << edge[i].src << " " << edge[i].dest << " " << edge[i].weight;
            cout << endl;
        }
    }

    /**
     * @brief TIME COMPLEXITY: O(VE)
     * 
     * @param adj 
     * @param V 
     * @param s 
     * @return vector<int> 
     */
    void bellmanFordAlgo(int s)
    {
        vector<int> dist(V, INT_MAX);
        dist[s] = 0;

        for (int count=0; count<V-1; count++)
        {
            for (int i=0; i<E; i++)
            {
                int u = edge[i].src;
                int v = edge[i].dest;
                int weight = edge[i].weight;

                if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
                    dist[v] = dist[u] + weight;
                    
            }
        }

        for (int i=0; i<E; i++)
        {
            int u = edge[i].src;
            int v = edge[i].dest;
            int weight = edge[i].weight;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
                cout << "Graph Contains Negative Weight Cycle" << endl;
        
        }

        for (int x: dist)
            cout << x << " ";
        cout << endl;

    }

};


int main()
{
    //EXAMPLE 1
    Graph graph(4, 5);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, -3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 3);

    //EXAMPLE 2
    // Graph graph(5, 8);
    // graph.addEdge(0, 1, -1);
    // graph.addEdge(0, 2, 4);
    // graph.addEdge(1, 2, 3);
    // graph.addEdge(1, 3, 2);
    // graph.addEdge(1, 4, 2);
    // graph.addEdge(3, 2, 5);
    // graph.addEdge(3, 1, 1);
    // graph.addEdge(4, 3, -3);

    graph.bellmanFordAlgo(0);

    return 0;
}