/**
 * @file KosarajuAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief This Algorithm is used to solve the strongly connected Components Problem.
 * 
 * NOTE: the given graph is Directed Unweighted Graph!!
 * Kosaraju's Algorithm is based on DFS
 * 
 * The problem/question is that we are given a directed graph, we need to find and print all the strongly connected components in it separated by new lines.
 *  
 * 
 * DFS can happen from any vertex, we don't have any order. But here in this case, what we want is if a Vertex V is reachable from U such that U is not reachable from V, then DFS of the vertex V should happen first because Vertex V is a Sink Vertex and U is source Vertex. So, DFS of vertex will mark V as visited then we do DFS for U. 
 * 
 * U ---> V (in a directed graph)
 * 
 * example:
 *  Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
 * 
 *          0 -----> 1 <----- 3
 *          ^       /         |
 *          |     /           |
 *          2<---             -->4
 * 
 * Here, 0-1-2 are sinked component and 3 is source vertex for it
 * Similarly 4 is a sink component and 3 is its vertex.
 * 
 * Therefore, 0-1-2 and 4 is visited first as they are sinked components, then vertex 3
 * 
 * And there multiple Algorithms to ensure the above idea. Kosaraju Algorithm is one of those algorithms that ensures these order by doin some pre-processing
 * 
 * 
 * We can use the idea of topological sorting for ensuring sink component first then its source vertex. 
 * It can also be called as Ordering the vertices in decreasing order of finish times in DFS..
 * (When you make a DFS recursive call for particular vertex, we call that time as start time for that vertex and when every adjacent is processed, that moment is called finish time).
 * 
 *  (NOTE: Topological Sort is used for Directed Acyclic Graph but here we will use Topological sort for Directed Cyclic Graph)
 * 
 * Algorithm Steps:
 * 1.) We first find Topological Sorting (Using DFS, it will be easier as we will get Stack of vertices).
 * 
 * 2.) Then, we will reverse the connections of all vertices with their adjacents. (The idea is strongly connected components will still be a same strongly connected components even after reversing directions)
 * (NOTE: Reversing all the edges is another way of finding transpose. For Adjacency Matrix we can simply find transpose of a matrix and we will get reversed edges. The below solution is for Adjacency List!!)
 * 
 * 3.) then we traverse using topological sort in DFS manner to print each connected components and print them in a new line.
 * 
 * This approach or Kosaraju Algorithm takes 3 DFS Traversals as you can see above!!
 * 
 * NOTE: The reason we use this algorithm is that in normal traversal, it may happen that we may print whole graph instead of strongly connected components as DFS may traverse through whole graph if strongly connected component is connected with other component.
 * 
 * [NOTE: And also why we can't simply traverse the graph in reverse order i.e. from destination to source is that for some graphs we may get correct answer but for some graphs the output may not be correct.
 * 
 * First Step ensures that we go from sinked side to source side which can be done using stack obtained from topological sort!
 * 
 * Another problem is that we don't only need to ensure that we traverse from sink side to source side, we also need to ensure that the vertices we print together are actually strongly connected components. When you reverse a graph, the strongly connected components stay strongly connected. That's the idea that we do step 2.
 * 
 * Let's see a new counter example to see why the other approach of dest to source(V-1 to 0) traversal would not work and also why we need Step 2:-
 * This example will only give correct answer when kosaraju 3 steps together is implemented.
 * Example:
 * 
 *                  0
 *                /  ^
 *            1<-    |
 *          /  \    /
 *      2<-     ->3 
 * 
 * Step-1: 0 1 2 3
 * (NOTE: Suppose if we traverse from V-1(3 here) to 0 without step 2 i.e. reversing edges then it will print the whole graph as from 3 everything is reachable : 3-0-1-2 so, it will print everything as strongly connected component which is wrong because here 1-0-3 are one component but two is a different component and that's what is ensured by the reverse step (i.e. Step 2).
 * If we follow the Kosaraju algorithm, we get the correct answer.)
 * 
 * Step-2: Reversing all the edges
 *          
 *                  -> 0
 *                /     |
 *            ->1<-     |
 *          /      \    |
 *        2         3<-- 
 * 
 * Step-3: Following DFS Traversal on the Step-2 reverse graph using Step-1 Topological sort
 *      0 3 1
 *      2
 * 
 * Therfore, the reason for reversing the edges is to make sure that we have both way connectivity and strongly connected components, if you reverse their edges stay/remains strongly connected!! 
 * 
 *      
 * ]
 * That's why we always use Topological sorted manner traversal to solve above problems.
 * 
 * 
 * Example: 
 *  Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 1);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 4);

    O/P: 
    0
    1 2
    3
    4 5

    The output here can be arranged in any order as long as the strong connected components are shown correctly.
    like: 
    0
    2 1
    3
    5 4

    So, many permutations can be produced but the strongly connected components are unique.

    Ex-2: 
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);

    O/P:
    0 1 2
    3
    4

    The output we get from this below code is:
    3
    4
    0 2 1

    This is another example that the strongly connected components can be arranged in any order as long as they are following kosaraju rule.

 * @version 0.1
 * @date 2022-12-01 05:50 PM
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

    public:
    Graph(int V)
    {
        this->V = V;
        this->adj = new vector<int> [V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void DFSTopo(int source, stack<int> &s, vector<bool> &visited)
    {
        visited[source] = true;

        for (int v: adj[source])
        {
            if (!visited[v])
                DFSTopo(v, s, visited);
        }

        s.push(source);

    }

    void KDFS(vector<int> kadj[], int source, vector<bool> &kvisited)
    {
        kvisited[source] = true;
        cout << source << " ";

        for (int v: kadj[source])
        {
            if (!kvisited[v])
                KDFS(kadj, v, kvisited);
        }

    }

    stack<int> topologicalSort()
    {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i=0; i<V; i++)
            if (visited[i] == false)
                DFSTopo(i, s, visited);
            
        return s;
    }

    /**
     * @brief TIME COMPLEXITY: O(V+E)
     * 
     * NOTE: This algorithm is not the best algorithm for finding Strongly connected components. There exists a better algorithm called Tarjan Algorithm that finds the strongly connected components in one DFS Traversal of a Graph.
     * 
     * Kosaraju uses Three DFS Traversals of a Graph.
     * 
     */
    void kosarajuAlgo()
    {
        //O(V+E)
        stack<int> ks = topologicalSort();

        //O(V+E)
        vector<int> *kadj = new vector<int>[V];
        for (int i=0; i<V; i++)
        {
            for (int v: adj[i])
            {
                kadj[v].push_back(i);
            }
        }

        //O(V+E)
        vector<bool> kvisited(V, false);
        while (!ks.empty())
        {
            int u = ks.top();
            ks.pop();

            if (!kvisited[u])
            {
                KDFS(kadj, u, kvisited);
                cout << endl;
            }
            
        }

    }

};

int main()
{
    //EXAMPLE 1
    // Graph graph(5);
    // graph.addEdge(0, 2);
    // graph.addEdge(2, 1);
    // graph.addEdge(1, 0);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 3);

    //EXAMPLE 2
    // Graph graph(6);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 1);
    // graph.addEdge(1, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 4);

    //EXAMPLE 3
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);

    //To check Topological Sort
    // stack<int> s = graph.topologicalSort();
    // while (!s.empty())
    // {
    //     int u = s.top();
    //     s.pop();

    //     cout << u << " ";
    // }

    graph.kosarajuAlgo();

    return 0;
}