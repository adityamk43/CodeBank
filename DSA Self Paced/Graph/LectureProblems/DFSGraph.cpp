/**
 * @file DFSGraph.cpp
 * @author ADITYA BHARDWAJ
 * @brief FOR DIRECTED AND UNDIRECTED GRAPH
 * 
 * FEW APPLICATIONS OF DFS:
 * 
 * 1.) Cycle Detection
 * 2.) Topological Sorting
 * 3.) Strongly Connected Components
 * 4.) Solving Maze and Similar Puzzles (Backtracking)
 * 5.) Path Finding
 * 
 * @version 0.1
 * @date 2022-11-27 05:11 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;

    cout << s << " ";

    for (int x: adj[s])
        if (visited[x] == false)
            DFSRec(adj, x, visited);
    

}

/**
 * @brief TIME COMPLEXITY: O(V+E)
 * 
 * @param adj 
 * @param V 
 * @param s 
 */
void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];

    for (int i=0; i<V; i++)
        visited[i] = false;
    
    DFSRec(adj, s, visited);
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{	
    int V=5;
	vector<int> adj[V];

    /**
     * @brief 
     * 
     *      0 ------ 1
     *      |        | \
     *      |        |   4
     *      |        | / 
     *      2 ------ 3
     * 
     */
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 

    return 0;
}