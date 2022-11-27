/**
 * @file NoofIslandsDFS.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * We have to find total number of cyclic graphs in a disconnected graph
 *  (or number of connected components in a graph)
 * 
 * We have already done this question using BFS and this is a solution for same problem using DFS
 * @version 0.1
 * @date 2022-11-27 05:26 PM
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
int DFSIsland(vector<int> adj[], int V)
{
    bool visited[V];
    int count = 0;

    for (int i=0; i<V; i++)
        visited[i] = false;
    
    for (int i=0; i< V; i++)
    {
        if (visited[i] == false)
        {
            count++;
            DFSRec(adj, i, visited);
        }
    }

    return count;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{	
    /**
     * @brief 
     *         1
     *       /  |       3 --- 4
     *      0   |
     *       \ |
     *        2
     */
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Following is No of Islands in a given graph/Number of connected components: " << endl; 
	cout << DFSIsland(adj,V) << endl; 

    return 0;
}