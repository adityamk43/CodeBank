/**
 * @file MinimumCoins.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * In this problem, we are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the given coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.
 * 
 * The above question can also be solved using greedy approach as we did in greedy track but we also came to knew that greedy approach doesn't work with all test cases, it only work for some cases and for Indian or US currencies, thus, D.P. solution comes in to rescue for such cases. Let's see!!
 * 
 * @version 0.1
 * @date 2022-12-20 06:06 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION WITH OVERLAPPINGS
 * 
 * TIME COMPLEXITY: O(2^n) [Either we pick coin or not so, 2^n]
 * AUXILIARY SPACE: O(n)
 * 
 * @param coins 
 * @param n 
 * @param value 
 * @return int 
 */
// int minCoins(int coins[], int n, int value)
// {
//     if (value==0)
//         return 0;

//     int res = INT_MAX;

//     for (int i=0; i<n; i++)
//     {
//         if (coins[i]<=value)
//         {
//             int sub_res = minCoins(coins, n, value-coins[i]);

//             if (sub_res!=INT_MAX)
//                 res = min(res, 1+sub_res);
//         }
//     }

//     return res;
// }

/**
 * @brief USING D.P. TABULATION TECHNIQUE WITH SINGLE PARAMETER ARRAY AS ONLY VALUE WILL BE CHANGING IN TERMS OF PARAMETER
 * 
 * TIME COMPLEXITY: ⊝(n*value)
 * AUXILIARY SPACE: ⊝(value)
 * 
 * @param coins 
 * @param n 
 * @param value 
 * @return int 
 */
int minCoins(int coins[], int n, int value)
{
    int dp[value+1];

    dp[0]=0;

    for (int i=1; i<=value; i++)
        dp[i] = INT_MAX;

    for (int i=1; i<=value; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i-coins[j]];

                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], 1+sub_res);
            }
        }
    }

    return dp[value];
}

int main()
{
    //EXAMPLE 1
    int coins[] = {25, 10, 5};
    int value=30;

    //EXAMPLE 2
    // int coins[] = {9, 6, 5, 1};
    // int value=11;

    //EXAMPLE 3
    // int coins[] = {3, 4, 1};
    // int value=5;
    
    int n = sizeof(coins)/sizeof(coins[0]);

    cout << minCoins(coins, n, value) << endl;

    return 0;
}