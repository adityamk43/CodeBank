/**
 * @file CoinChange.cpp
 * @author ADITYA BHARDWAJ
 * @brief  
 * 
 * We are given an infinite amount of every given coin types, we need to find the maximum number of ways in which we can fulfill the given sum with different coin types combinations. This question's Recursive is very similar to 0-1 Knapsack Problem.
 * 
 * Eg: Coins[] = {1, 2, 3}
 *              Sum=4
 *  O/P: 4
 * (1+1+1+1, 2+2, 2+1+1, 1+3)
 * 
 * Sim, 
 * for Coins[] = {2, 5, 3, 6}
 *          Sum=10    
 *      O/P: 5
 *      (2+2+2+2+2, 5+5, 3+3+2+2, 6+2+2, 5+2+3)
 * 
 * VERY VERY VERY IMPORTANT NOTE: This Coin Change problem is one of those category problem called NP-Complete or NP-Hard because there doesn't exist a polynomial time solution and there is no known polynomial time solution for this problem and the solution here(⊝(n*s)) looks like polynomial but this is not polynomial, it is called pseudo polynomial because we are depending upon the value of the variable s, so if "s" is very very high then this time complexity would become very very high. So, this is Pseudo Polynomial Solution for Coin Change Problem using Dynamic Programming(D.P.).
 * 
 * @version 0.1
 * @date 2022-12-18 02:30 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Idea for the Recursive Solution
 * 
 * Coins = [x0, x1, ......., xn-1]
 * sum = s
 * 
 * NOTE: We begin with the last element in Coins array. We can also start from first element, there are two ways but we are preferring to start from last element of array.
 * 
 * We consider two choices for every coin
 *      a) Included
 *      b) Not included
 * 
 * We then return sum of the results of these two recursive calls
 * 
 *                     ([1, 2, 3], s=4)
 *                       /          \
 *            ([1, 2, 3], s=1)   ([1, 2], s=4)
 *               Included        Not Included
 */
/**
 * @brief Naive Recursive Solution
 * TIME COMPLEXITY: ⊝(2^n) Exponential
 * 
 * Since, in worst case s and n will be same and coins will have only 1 as a coin value of type. so we will get 2^n nodes in recursion tree
 * 
 * AUXILIARY SPACE: ⊝(s) 
 * 
 * @param coins
 * @param n
 * @param s
 * @return int 
*/
// int countWays(int coins[], int n, int s)
// {
//     if (s==0)
//         return 1;
//     if (s<0)
//         return 0;
//     if (n==0)
//         return 0;
    
//     return countWays(coins, n-1, s) + countWays(coins, n, s-coins[n-1]);
// }


/**
 * @brief Idea of D.P. Tabulation Approach
 * 
 * A (n+1)*(s+1) array where dp[i][j] is going to store result for first i coins and j sum.
 * 
 *              1 if s=0;
 * dp[i][j] =   0 if s>0 and n=0
 *              dp[i-1][j] if coin[i-1] > j
 *              dp[i-1][j-coin[i-1]] in all other cases
 * 
 * TIME COMPLEXITY: ⊝(n*s)
 * AUXILIARY SPACE: ⊝(n*s)
 * 
 * @param coins 
 * @param n 
 * @param s 
 * @return int 
 */
int countWays(int coins[], int n, int s)
{
    int dp[n+1][s+1];

    for (int i=0; i<=n; i++)
        dp[i][0] = 1;

    for (int j=1; j<=s; j++)
        dp[0][j] = 0;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=s; j++)
        {
            dp[i][j] = dp[i-1][j];

            if (coins[i-1] <= j)
                dp[i][j] += dp[i][j-coins[i-1]];
        }
    }

    return dp[n][s];
}

int main()
{
    int coins[] = {1, 2, 3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 4;

    cout << countWays(coins, n, sum) << endl;

    return 0;
}