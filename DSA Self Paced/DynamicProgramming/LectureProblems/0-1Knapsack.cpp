/**
 * @file 0-1Knapsack.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * In this problem we are given item's weight and its value/profit and the maximum capacity of knapsack.
 * We need to find the maximum items that we can fit inside this knapsack ensuring maximum value and the total weight of those items are less than or equal to total weight of the knapsack.
 * 
 * @version 0.1
 * @date 2022-12-20 11:09 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION WITH OVERLAPPINGS
 * 
 * TIME COMPLEXITY: O(2^n) 
 *      exponential as either you pick that item or doesn't no partial pickings like fractional knapsack and hence, the name 0-1 knapsack.
 * 
 * AUXILIARY SPACE: O(n)
 * 
 * @param W 
 * @param val 
 * @param wt 
 * @param n 
 * @return int 
 */
// int knapSack(int W, int val[], int wt[], int n)
// {
//     if (n==0 || W==0)
//         return 0;
    
//     if (wt[n-1] > W)
//         return knapSack(W, val, wt, n-1);
    
//     else
//         return max(val[n-1] + knapSack(W-wt[n-1], val, wt, n-1), knapSack(W, val, wt, n-1));
// }

/**
 * @brief D.P. TABULATION TECHNIQUE!!
 * 
 *      TIME COMPLEXITY: ⊝(nW)
 *      AUXILIARY SPACE: ⊝(nW)
 * 
 * IMPORTANTNOTE: This solution has pseudo polynomial time and not fully polynomial as its time complexity depends on the value of W.
 * It may happen that for very higher value of W (for eg: 5000), this(D.P.) solution time complexity may become worse than the recursion one which was O(2^n).
 * 
 * Hence, this solution should only be applicable to use if the value of W is not very higher.
 * 
 * Thus, it's one of the N.P.-Hard Solution as 0-1 Knapsack problem doesn't have a proper optimised solution so far till present but this D.P. solution is pseudo polynomial and applicable for lower values of W!!!!
 * 
 * @param W 
 * @param val 
 * @param wt 
 * @param n 
 * @return int 
 */
int knapSack(int W, int val[], int wt[], int n)
{
    int dp[n+1][W+1];

    //base cases as of we did in recursion one
    for (int i=0; i<=n; i++)
        dp[i][0] = 0;

    for (int j=0; j<=W; j++)
        dp[0][j] = 0;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=W; j++)
        {
            if (wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
        }
    }

    return dp[n][W];
}

int main()
{
    //EXAMPLE 1
    // int value[] = {10, 40, 30, 50};
    // int weight[] = {5, 4, 6, 3};
    // int W=10;

    //EXAMPLE 2
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W=50;

    int n=sizeof(value)/sizeof(value[0]);

    cout << knapSack(W, value, weight, n) << endl;

    return 0;
}