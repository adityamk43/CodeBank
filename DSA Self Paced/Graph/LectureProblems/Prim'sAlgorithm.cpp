/**
 * @file Prim'sAlgorithm.cpp
 * @author ADITYA BHARDWAJ
 * @brief Prim's Algroithm for Minimum Spanning Tree (Using Adjacency Matrix)
 * @version 0.1
 * @date 2022-11-30 08:05 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#define V 4
using namespace std;

/**
 * @brief TIME COMPLEXITY: ⊝(V^2)
 * 
 * @param graph 
 * @return int 
 */
int primsMSTAlgo(int graph[V][V])
{
    int res = 0;
    int key[V];
    fill(key, key+V, INT_MAX);
    key[0] = 0;
    
    bool mstSet[V] = {false};

    for (int count=0; count<V; count++)
    {
        int u=-1;
        // int min_val = INT_MAX;

        // for (int i=0; i<V; i++)
        // {
        //     if (mstSet[i] == false && key[i] < min_val)
        //     {
        //         min_val = key[i];
        //         u=i;
        //     }
        // }

        for (int i=0; i<V; i++)
            if ( !mstSet[i] && (u==-1 || key[i] < key[u]))
                u = i;
    
        mstSet[u] = true;
        res += key[u];

        for (int i=0; i<V; i++)
        {
            if (graph[u][i] != 0 && mstSet[i] == false)
                key[i] = min(key[i], graph[u][i]);
        }
    }

    return res;

}

int main()
{   

    /**
     * @brief (x) => weight of that edge
     *         n => vertex number [starts from 0]
     * 
     *           1
     *   (5)  / |   \  (15)
     *      /   |    \ 
     *     0    |(10) 3
     *      \   |    /
     *   (8) \  |  /   (20)
     *          2 
     *      
     * 
     */
    int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

    cout << primsMSTAlgo(graph);

    return 0;
}