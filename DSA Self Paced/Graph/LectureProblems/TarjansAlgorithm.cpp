/**
 * @file TarjansAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief Kosaraju's Algorithm uses 2 DFS Traversals to find Strongly Connected Components(SCC).
 * 
 * With the help of Tarjan's Algorithm, we can find SCC in One DFS Traversal only!
 * 
 * It uses the concept of Articulation Point Algorithm like lowest reachable discovery time and discovery time.
 * 
 * Let us see the implmentation now to get better understanding!!
 * 
 * @version 0.1
 * @date 2022-12-03 03:53 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

    void tarjansDFS(int u, bool *stackMember, int *low, int *disc, stack<int> *st)
    {
        static int time = 0;

        disc[u] = low[u] = ++time;

        stackMember[u] = true;

        st->push(u);

        for (int v: adj[u])
        {
            if (disc[v] == -1)
            {
                tarjansDFS(v, stackMember, low, disc, st);

                low[u] = min(low[u], low[v]);
            }
            else if (stackMember[v] == true)
                low[u] = min(low[u], disc[v]);
        }

        int w=0;

        if (low[u] == disc[u])
        {
            while (st->top() != u)
            {
                //both initialisation works but second one is more safe!
                // w = st->top();
                w = (int) st->top();
                st->pop();
                cout << w << " ";
                stackMember[w] = false;
            }


            //both initialisation works but second one is more safe!
            // w = st->top();
            w = (int) st->top();
            st->pop();
            cout << w << endl;
        }

    }

    public: 

    Graph(int V)
    {
        this->V = V;
        adj = new vector<int> [V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    /**
     * @brief TIME COMPLEXITY: O(V+E) As we are doing DFS Traversal Only
     * 
     */
    void tarjansAlgo()
    {
        int *disc = new int[V];
        int *low = new int[V];
        bool *stackMember = new bool[V];
        
        for (int i=0; i<V; i++)
        {
            disc[i] = low[i] = -1;
            stackMember[i] = false;
        }

        stack<int> *st = new stack<int>();

        for (int i=0; i<V; i++)
            if (disc[i] == -1)
                tarjansDFS(i, stackMember, low, disc, st);

    }

};

int main()
{
    cout << "SCCs in the graph using Tarjan's Algorithm \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	
    g.tarjansAlgo();

    return 0;
}