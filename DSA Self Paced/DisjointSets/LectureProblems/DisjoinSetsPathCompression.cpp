/**
 * @file DisjoinSetsPathCompression.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to find root. The idea of path compression is to make the found root as parent of x so that we don't have to traverse all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.

Let the subset {0, 1, .. 9} be represented as below and find() is called
for element 3.

                 9
             /   |   \
            4    5    6
          /    \    /   \
        0      3  7      8
             /  \
           1     2



When find() is called for 3, we traverse up and find 9 as representative
of this subset. With path compression, we also make 3 as the child of 9 so
that when find() is called next time for 1, 2 or 3, the path to root is reduced.

                    9
             /   |   \      \ 
            4    5    6       3
          /         /   \    /  \
        0         7      8  1   2
 *
 * @version 0.1
 * @date 2022-12-04 03:15 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> myPair;

/**
 * @brief 
 * The two techniques Union By Rank and Path Compression complement each other. The time complexity of each operation becomes even smaller than O(Logn). In fact, amortized time complexity effectively becomes small constant. 
 * 
 * For m operations on V elements:
 * 
 * TIME COMPLEXITY: O(m α(n))
 * 
 * where α(n) <= 4 even for the largest values that can be represented in this universe!!
 * 
 * NOTE: α(n) is Inverse Ackermann Function
 * 
 * Thus, we get constant time on average for m operations and please note that O(m α(n)) is amortised time complexity.
 * 
 * Amortised means we take average of m operations and the result that we get is called amortised value.
 * i.e, we compute the time complexity of m operations and divide it by m.
 * 
 * There might be one particular operation that might be costly but on average for m operations, you get the constant time.
 * 
 * NOTE: Proof of the above is given in the Cormen Book!!
 * 
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
            parent[u] = find(parent[u]);
        
        return parent[u];
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