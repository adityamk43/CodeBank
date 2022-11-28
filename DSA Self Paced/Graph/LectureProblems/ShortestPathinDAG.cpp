/**
 * @file ShortestPathinDAG.cpp
 * @author ADITYA BHARDWAJ
 * @brief There are many algorithms to find shortest path in DAG like Dijkstra (O(ElogV)), Bellman Ford(O(VE)).
 *
 * As you can see although Dijsktra is better here but we can decrease and optimise the time complexity more using Topological Sorting!!
 *
 * Let's see How!!
 *
 * Basic Idea is when doing Topological sorting using any one DFS/BFS, we observe that we move in forward direction since there is no cycles, so traversing topological sort and updating shortest distances array automatically gives us Shortest Path from Source to Destination.
 *
 * TADA!!!
 *
 * @version 0.1
 * @date 2022-11-29 12:02 AM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#define INF INT_MAX 
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(V+E)
 *
 * @param adj
 * @param V
 */


class AdjListNode 
{ 
	int v; 
	int weight; 
public: 
	AdjListNode(int _v, int _w) { v = _v; weight = _w;} 
	int getV()	 { return v; } 
	int getWeight() { return weight; } 
}; 

class Graph
{
    int V;
    vector<AdjListNode> *adj;
    vector <int> toplogsort;

    void topologicalSorting(int V);

public:
    Graph(int V);

    void addEdge(int u, int v, int weight);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSorting(int V)
{
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (AdjListNode x : adj[i])
            indegree[x.getV()]++;
    }
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        toplogsort.push_back(u);

        for (AdjListNode x : adj[u])
        {
            int v = x.getV();

            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }
}

void Graph::shortestPath(int s)
{
    int dist[V];

    for (int i=0; i<V; i++)
        dist[i] = INF;

    dist[s] = 0;

    topologicalSorting(V);

    for (int i=0; i<V; i++)
    {
        int u = toplogsort[i];
        
        //This if condition if for those vertex which can't be reached through source. (Refer to Second Graph Example here in main function!!)
        if (dist[u] != INF)
        {
            for (AdjListNode x: adj[u])
            {
                int v = x.getV();

                if (dist[v] > dist[u] + x.getWeight())
                {
                    dist[v] = dist[u] + x.getWeight();
                } 

            }
        }
        
    }

    for (int i = 0; i < V; i++) 
		(dist[i] == INF)? cout << "INF ": cout << dist[i] << " "; 
}

int main()
{

    //EXAMPLE 1
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);
    int s = 0;

    //EXAMPLE 2
    // Graph g(4);
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 3);
    // g.addEdge(1, 3, 2);
    // g.addEdge(2, 3, 4);
    // int s = 1;

    cout << "Following are shortest distances from source " << s << ": \n";
    g.shortestPath(s);

    return 0;
}