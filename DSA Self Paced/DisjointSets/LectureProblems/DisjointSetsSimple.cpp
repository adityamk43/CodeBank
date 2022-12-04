/**
 * @file DisjointSetsSimple.cpp
 * @author ADITYA BHARDWAJ
 * @brief Simple Disjoint Set Implementation:
 * 
 * A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
 * 
 * For Example:

Consider that there are 5 students in a classroom namely, A, B, C, D, and E.

They will be denoted as 5 different subsets: {A}, {B}, {C}, {D}, {E}.


After some point of time, A became friends with B, and C became friend with D. So, A and B will now belong to a same set and C and D will now belong to another same set.

The disjoint data structure will now be: {A, B}, {C, D}, {E}.

If at any point in time, we want to check that if any two students are friends or not, then we can simply check whether they belong to the same set.

As explained above, there are generally two types of operations performed on a Disjoint-Set data structure:
Union(A, B): This operation tells to merge the sets containing elements A and B respectively by performing a Union operation on the sets.
Find(A): This operation tells to find the subset to which the element A belongs.


Implementation: The disjoint set data structure can be implemented using a Parent array representation. If we are dealing with n items, i’th element of the array represents the i’th item. More precisely, the i’th element of the array is the parent of the i’th item.

Application: There are a lot of applications of Disjoint-Set data structure. Consider the problem of detecting a cycle in a Graph. It can be easily solved using the Disjoint Set and Union-Find algorithm. This method assumes that the graph does not contain any self-loop.

 * 
 * @version 0.1
 * @date 2022-12-04 02:48 PM
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
 * Worst Case: O(n) for both find() and union()
 * 
 *  The implementation of union() and find() is naive and takes O(n) time in worst case. These methods can be improved to O(Logn) using Union by Rank or Height.
 * 
 */
struct DisjointSets
{
    int n;
    int *parent;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n];

        for (int i=0; i<n; i++)
            parent[i] = i;
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

        if (x_rep != y_rep)
            parent[y_rep] = x_rep;
    }
};

int main()
{
    DisjointSets ds(5);

    // ds.union_merge(0, 2);
    // ds.union_merge(2, 4);

    // cout << ds.find(4) << endl;
    // cout << ds.find(2) << endl;
    // cout << ds.find(3) << endl;

    //Example to check worst case scenario. (Soln and optimisation for this is done through union by rank implementation)
    ds.union_merge(2, 3);
    ds.union_merge(1, 2);
    ds.union_merge(0, 1);

    cout << ds.find(4) << endl;
    cout << ds.find(1) << endl;
    cout << ds.find(2) << endl;
    cout << ds.find(3) << endl;

    return 0;
}