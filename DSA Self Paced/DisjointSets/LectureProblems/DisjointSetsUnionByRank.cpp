/**
 * @file DisjointSetsUnionByRank.cpp
 * @author ADITYA BHARDWAJ
 * @brief In this implementation we are going top optimise the simple union by using rank system to prevent formation of skewed or chain like tree in worst case scenario which will optimise the Time Complexity from O(n) to O(logn).
 * 
 * NOTE: The previous union() and find() are naïve and the worst case time complexity is linear. The trees created to represent subsets can be skewed and can become like a linked list. Following is an example of the worst case scenario.
 * 
 * @version 0.1
 * @date 2022-12-04 03:00 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> myPair;

/**
 * @brief TIME COMPLEXITY: 
 * 
 * The below operations can be optimized to O(Log n) time complexity in worst case. The idea is to always attach smaller depth tree under the root of the deeper tree. This technique is called union by rank. The term rank is preferred instead of height because if path compression technique (implemented in next code) is used, then rank is not always equal to height. Also, size (in place of height) of trees can also be used as rank. Using size as rank also yields worst case time complexity as O(Logn).
 * 
 * 
 */
struct DisjointSets
{
    int n;
    int *parent;
    int *ranks;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n];
        ranks = new int[n];

        for (int i=0; i<n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            return find(parent[u]);
        
        return u;
    }

    void union_merge(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        
        if (x_rep == y_rep)
            return;

        if (ranks[x_rep] < ranks[y_rep])
            parent[x_rep] = y_rep;
        else if (ranks[x_rep] > ranks[y_rep])
            parent[y_rep] = x_rep;
        
        else
        {
            parent[y_rep] = x_rep;
            ranks[x_rep]++;
        }
    }
};

int main()
{
    DisjointSets ds(5);

    ds.union_merge(2, 3);
    ds.union_merge(1, 2);
    ds.union_merge(0, 1);

    //After optimisation The output and representatives will be different from simple implemenation!
    cout << ds.find(4) << endl;
    cout << ds.find(1) << endl;
    cout << ds.find(2) << endl;
    cout << ds.find(3) << endl;

    // ds.union_merge(3, 4);
    // ds.union_merge(2, 3);
    // ds.union_merge(1, 2);
    // ds.union_merge(0, 1);

    // cout << ds.find(4) << endl;
    // cout << ds.find(2) << endl;
    // cout << ds.find(3) << endl;

    // cout << ds.parent[3] << endl;
    // cout << ds.ranks[3] << endl;

    return 0;
}