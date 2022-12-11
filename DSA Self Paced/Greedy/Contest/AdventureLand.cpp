/**
 * @file AdventureLand.cpp
 * @author ADITYA BHARDWAJ
 * @brief You have an undirected connected graph having V nodes and E edges. Edges have weight representing the time in seconds it takes to travel through that edge. An adventure tour is being organised on this graph. Given a source node from where you will begin the tour and K distinct flags, corresponding to K distinct nodes, are also kept at the source node. You have to post these flags at their respective nodes (flag 1 will be placed at node 1, 2 will be at node 2, and so on...), by carrying them to those nodes one by one. You can visit nodes in any order of your choice. At a particular instance, you can only carry one flag along with you. Tour ends when all the K flags have been posted at their respective nodes. Find the minimum time in seconds to complete the tour, starting from the source node.

INPUT:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case, contains two space seperated integers, corresponding to V and E, as the number of nodes in the graph and number of edges present respectively. E lines corresponding to edges follow. Every edge is described by 3 integers, u, v corresponding to an undirected edge of weight between u and v. Then next line contains two integers, S and K, corresponding to source node and total number of nodes to be flagged. K space seperated distinct integers follow, corresponding to the respective nodes to be flagged.

OUTPUT:
Print the minimum time in seconds, required to complete the tour.

CONSTRAINTS:
2 <= V <=1000
V <= E <= 10000
1 <= W <= 60
1 <= S <= V
1 <= K <= V-1

NOTE: All the nodes corresponding to K flags are distinct, and the source node does not corresponds to any flag given.

EXAMPLE:
I/P:
2
5 6
1 2 11
1 3 2
1 4 11
1 5 10
2 4 12
3 4 13
4 2
2 5
2 1
1 2 5
1 1
2

O/P:
45
5

Explaination:
From source 4, we visit node 2 , post the flag corresponding to 2 there and come back to 4, taking 24 seconds, after that we pick flag corresponding to node 5 and reach 5 through node 1 taking another 21 seconds. As all required nodes have been flagged, tour ends, taking a total of 45 seconds.

 * @version 0.1
 * @date 2022-12-11 04:04 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> myPair;

vector<long long int> dijkstraAlgo(vector<vector<long long int>> adj[], long long int V, long long int S)
{
    vector<long long int> dist(V, INT_MAX);
    vector<bool> finalised(V, false);

    dist[S] = 0;

    priority_queue<myPair, vector<myPair>, greater<myPair>> pq;
    //O(logV)
    //pair -> (weight, vertex)
    pq.push(make_pair(0, S));

    //O(V)
    while (!pq.empty())
    {
        //O(logV)
        long long int u = pq.top().second;
        pq.pop();

        if (finalised[u] == true)
            continue;
        
        finalised[u] = true;

        //O(ElogV)
        for (vector<long long int> mp: adj[u])
        {
            long long int v = mp[0];
            long long int weight = mp[1];

            //Relax Operation
            if (finalised[v] == false && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;

}

long long int adventureLand(vector<vector<long long int>> adj[], long long int V, long long int S, long long int K, long long int flags[])
{

    vector<long long int> all_dist = dijkstraAlgo(adj, V, S); 

    vector<long long int> distances; 

    for (long long int i=0; i<K; i++)
    {
        distances.push_back(all_dist[flags[i]]);
    }

    long long int ans = 0; // initially answer is 0.

    sort(distances.begin(), distances.end());

    for (long long int i=0; i<K-1; i++) 
        ans += 2 * (distances[i]); 

    ans += distances[K - 1]; // for the last node, we only visit it, no need to come back to source

    return ans;
}

int main()
{

    long long int t;
    cin >> t;

    while (t--)
    {
        long long int V, E;
        cin >> V >> E;
        vector<vector<long long int>> adj[V];

        for (long long int i=0; i<E; i++)
        {
            long long int u, v, w;
            cin >> u >> v >> w;

            u--, v--;
            vector<long long int> v1;
            v1.push_back(v);
            v1.push_back(w);
            vector<long long int> v2;
            v2.push_back(u);
            v2.push_back(w);

            adj[u].push_back(v1);
            adj[v].push_back(v2);
        }

        long long int S;
        cin >> S;
        S--;
        long long int K;
        cin >> K;

        long long int flags[K];

        for (long long int j=0; j<K; j++)
        {
            cin >> flags[j];
            flags[j]--;
        }

        cout << adventureLand(adj, V, S, K, flags) << endl;
    }
}