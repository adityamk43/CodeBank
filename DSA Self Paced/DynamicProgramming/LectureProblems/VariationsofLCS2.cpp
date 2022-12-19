/**
 * @file VariationsofLCS2.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * This is the 2nd file about different problems which are variations of LIS problem.
 * 
 * IMPORTANTNOTE: These below problems are very very important questions!!
 * 
 * @version 0.1
 * @date 2022-12-20 12:08 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> myPair;

bool compareBridges(myPair p1, myPair p2)
{
    if (p1.first == p2.first)
    {
        if (p1.second < p2.second)
            return true;
        else
            return false;
    }
    else if (p1.first < p2.first)
        return true;
    else
        return false;
}

int ceilingIdx(int tail[], int l, int r, int x)
{
    while (r>l)
    {
        int m = l + (r-l)/2;

        if (tail[m] >= x)
            r = m;
        else
            l=m+1;
    }

    return r;
}

/**
 * @brief
 * In this problem we are given a bridge pairs using which we have to build bridges but the rule/condition is that no bridges should cross each other and we have to build maximum number of bridges following this rule/condition!!
 * 
 * Ex:
 * I/P: {(6, 2), (4, 3), (2, 6), (1, 5)};
 * 
 * O/P: 2
 * 
 *      1   2  ...   6
 *        \   \
 *      1..5   6
 * 
 * (1, 5) (2, 6)
 * 
 * All other bridges if build will cross each other so the maximum bridges is 2 shown above that can be build.
 * 
 *        TIME COMPLEXITY: Same as optimised LIS O(nlogn)
 *        AUXILIARY SPACE: Same as optimised LIS ⊝(n)
 * 
 * @param bridges 
 * @param n 
 * @return int 
 */
int buildBridges(myPair bridges[], int n)
{
    sort(bridges, bridges+n, compareBridges);

    int tail[n];
    int len=1;

    tail[0] = bridges[0].second;

    for (int i=1; i<n; i++)
    {
        if (bridges[i].second > tail[len-1])
        {
            tail[len] = bridges[i].second;
            len++;
        }
        else
        {
            int c = ceilingIdx(tail, 0, len-1, bridges[i].second);
            tail[c] = bridges[i].second;
        }
    }

    return len;
}

/**
 * @brief 
 * In this problem we are given a pairs in which first member of pair is always smaller than its second member.
 * eg: (a,b) then a<b.
 * We have to find the length of the longest chain of Pairs in such a way that if we have {(a, b), (c, d)}
 * then a<b and b<c
 * 
 * Eg:
 * I/P: {(5, 24) (39, 60) (15, 28) (27, 40) (50, 90)}
 * O/P: {(5, 24) (27, 40) (50, 90)}
 *  
 * USING D.P. Soln. of variation of LIS:
 * 1.) Sort the array of pairs according to the first values.
 * 2.) Find the LIS of the sorted array (where arr[i].first > arr[j].second).
 * 
 *        TIME COMPLEXITY: O(n^2) same as normal LIS technique
 *        AUXILIARY SPACE: ⊝(n)
 *   
 * IMPORTANTNOTE: This solution can also be done using greedy approach reducing the time complexity to ⊝(nlogn).
 * This problem can also be seem similar/twisted/same version to Activity Selection Problem which is solved using greedy approach where given tasks have start and finish time and processor should complete task in such a way that no two tasks time intervals should overlap each other!! or like conference room meeting problem where no meetings should collide in a conference room at a time!!
 * 
 * ANOTHER IMPORTANTNOTE: This problem can also be seen as an another/specific version of Build Bridges with rules like {(a, b) (c, d)} a<b & b<c. which makes that problem more easier to solve as crossing of bridges may occur rarely now due to the a<b & b<c rules here.
 * 
 * @param pairs 
 * @param n 
 * @return int 
 */
int longestChainOfPairs(myPair pairs[], int n)
{
    sort(pairs, pairs+n);

    int lis[n];
    lis[0] = 1;

    for (int i=1; i<n; i++)
    {
        lis[i] = 1;

        for (int j=0; j<i; j++)
        {
            if (pairs[i].first > pairs[j].second)
            {
                lis[i] = max(lis[i], 1+lis[j]);
            }
        }
    }

    int max_val = lis[0];

    for (int i=0; i<n; i++)
        max_val = max(max_val, lis[i]);

    return max_val;
}

//LONGEST CHAINS OF PAIRS USING GREEDY APPROACH SIMILAR TO ACTIVITY SELECTION OPTIMISING TIME COMPLEXITY TO ⊝(nlogn)
bool comparePairs(myPair p1, myPair p2)
{
    return p1.second < p2.second;
}

int longestChainOfPairsGreedy(myPair pairs[], int n)
{
    sort(pairs, pairs+n, comparePairs);

    int res=1;
    int prev=0;

    for (int i=1; i<n; i++)
    {
        if (pairs[i].first > pairs[prev].second)
        {
            res++;
            prev=i;
        }
    }

    return res;

}
int main()
{
    cout << endl;
    cout << "Choose which variation of LIS you want to see: " << endl;
    cout << "1. Building Bridges " << endl;
    cout << "2. Longest Chain of Pairs " << endl;
    cout << "3. Longest Chain of Pairs Using Greedy Approach(Activity Selection)-⊝(nlogn)" << endl;

    int option;
    cin >> option;

    cout << endl << "OUTPUT: ";
    switch(option)
    {
        case 1:
        {
            //EXAMPLE 1
            // myPair bridges[] = {
            //     {6, 2},
            //     {4, 3},
            //     {2, 6},
            //     {1, 5},
            //     {1, 3}
            // };
            //O/P: 3 => (1, 3) (1, 5) (2, 6)

            //EXAMPLE 2
            myPair bridges[] = {
                {8, 1},
                {1, 2},
                {4, 3},
                {3, 4},
                {2, 6},
                {6, 7},
                {7, 8},
                {5, 5}
            };
            //O/P: 5 => (1, 2) (3, 4) (5, 5) (6, 7) (7, 8)

            int n = sizeof(bridges)/sizeof(bridges[0]);

            //debuggin' for sort comparator
            // sort(bridges, bridges+n, compareBridges);
            // cout << endl;
            // for (int i=0; i<n; i++)
            // {
            //     cout << bridges[i].first << ":" << bridges[i].second << endl;
            // }
            
            cout << buildBridges(bridges, n);

            break;
        }

        case 2:
        {
            //EXAMPLE 1
            myPair pairs[] = {
                {5, 24},
                {39, 60},
                {15, 28},
                {27, 40},
                {50, 90}
            };
            //O/P: 3 => (5, 24) (27, 40) (50, 90)

            //EXAMPLE 2
            // myPair pairs[] = {
            //     {6, 8},
            //     {3, 4}
            // };
            //O/P: 2 => (3, 4) (6, 8)
            int n = sizeof(pairs)/sizeof(pairs[0]);

            //debuggin' for sorting
            // sort(pairs, pairs+n);
            // cout << endl;
            // for (int i=0; i<n; i++)
            // {
            //     cout << pairs[i].first << ":" << pairs[i].second << endl;
            // }

            cout << longestChainOfPairs(pairs, n) << endl;

            break;
        }

        case 3:
        {
            //EXAMPLE 1
            myPair pairs[] = {
                {5, 24},
                {39, 60},
                {15, 28},
                {27, 40},
                {50, 90}
            };
            //O/P: 3 => (5, 24) (27, 40) (50, 90)

            //EXAMPLE 2
            // myPair pairs[] = {
            //     {6, 8},
            //     {3, 4}
            // };
            //O/P: 2 => (3, 4) (6, 8)
            int n = sizeof(pairs)/sizeof(pairs[0]);

            //debuggin' for sorting
            // sort(pairs, pairs+n, comparePairs);
            // cout << endl;
            // for (int i=0; i<n; i++)
            // {
            //     cout << pairs[i].first << ":" << pairs[i].second << endl;
            // }

            cout << longestChainOfPairsGreedy(pairs, n) << endl;

            break;
        }

        default:{
            cout << "NOT A VALID OPTION!!" << endl;
            exit(0);
        }
    }

    return 0;
}