/**
 * @file DijsktraAlgoAdjacencyList.cpp
 * @author ADITYA BHARDWAJ
 * @brief It works similary like Prim's Algorithm but here we do relax operation:
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
 * @date 2022-12-01 03:45 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> myPair;

class Graph
{
    int V;
    list<myPair> *adj;

    public:
    Graph(int V)    
    {
        this->V = V;
        adj = new list<myPair> [V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    /**
     * @brief TIME COMPLEXITY: O((V+E)logV)
     * 
     */
    void dijkstraAlgo()
    {
        vector<int> dist(V, INT_MAX);
        vector<bool> finalised(V, false);

        dist[0] = 0;

        priority_queue<myPair, vector<myPair>, greater<myPair>> pq;
        //O(logV)
        //pair -> (weight, vertex)
        pq.push(make_pair(0, 0));

        //O(V)
        while (!pq.empty())
        {
            //O(logV)
            int u = pq.top().second;
            pq.pop();

            if (finalised[u] == true)
                continue;
            
            finalised[u] = true;

            //O(ElogV)
            for (myPair mp: adj[u])
            {
                int v = mp.first;
                int weight = mp.second;

                if (finalised[v] == false && dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        //O(V)
        for (int x: dist)
            cout << x << " ";
        cout << endl;

    }

};

int main()
{
    Graph graph(9);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 2, 11);
    graph.addEdge(1, 3, 8);
    graph.addEdge(2, 4, 7);
    graph.addEdge(2, 5, 1);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 6, 7);
    graph.addEdge(3, 7, 4);
    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 7, 2);
    graph.addEdge(6, 7, 14);
    graph.addEdge(6, 8, 9);
    graph.addEdge(7, 8, 10);

    graph.dijkstraAlgo();

    return 0;
}