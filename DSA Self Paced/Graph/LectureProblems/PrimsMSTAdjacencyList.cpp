/**
 * @file PrimsMSTAdjacencyList.cpp
 * @author ADITYA BHARDWAJ
 * @brief Prim's Algroithm for Minimum Spanning Tree (Using Adjacency List and Min Heap)
 * @version 0.1
 * @date 2022-11-30 08:55 PM
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
    list<pair<int, int>> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<myPair>[V];
    }

    void addEdge(int u, int v, int weight)
    {
        // pair can be made using curly brackets or make_pair() func :) simple formula that everybody should know and knows XD
        adj[u].push_back({v, weight});
        adj[v].push_back(make_pair(u, weight));
    }

    /**
     * @brief Time Complexity: O(ElogV)
     * 
     *      How it is derived: O(VlogV + (V+E)logV)
     *                         O((V+E)logV)
     *                      Since, in Connected Graph E = V-1
     * Therefore, 
     * Overall Time Complexity: O(ElogV)
     * 
     * @return int 
     */
    int primMST()
    {
        priority_queue<myPair, vector<myPair>, greater<myPair>> pq;

        vector<bool> mSet(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);

        key[0] = 0;

        // weight first then vertex, so that min heap is done on basis of weights as in pairs first variable is taken in consideration for sorting or min/max heap purpose
        pq.push(make_pair(0, 0));

        int res = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (mSet[u] == true)
                continue;

            mSet[u] = true;
            res += w;

            for (myPair mp : adj[u])
            {
                int v = mp.first;
                int weight = mp.second;

                if (mSet[v] == false && key[v] > weight)
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push(make_pair(key[v], v));
                }
            }
        }

        for (int i = 1; i < V; ++i)
            cout << parent[i] << "-" << i << endl;

        cout << endl;

        return res;
    }
};

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 20);

    cout << graph.primMST();

    return 0;
}