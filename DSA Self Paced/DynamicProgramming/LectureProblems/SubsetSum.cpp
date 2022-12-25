/**
 * @file SubsetSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given an array and a sum and we want to find those subsets of this array whose elements sum is equal to given sum variable.
 * 
 * @version 0.1
 * @date 2022-12-25 10:01 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION
 * 
 * TIME COMPLEXITY: 2^n leaves + 2^n-1 internal Nodes ~ O(2^n)
 * AUXILIARY SPACE: O(n)
 * 
 * @param arr 
 * @param n 
 * @param sum 
 * @return int 
 */
// int subsetSum(int arr[], int n, int  sum)
// {
//     if (n==0)
//         return sum==0? 1 : 0;
    
//     return subsetSum(arr, n-1, sum) + subsetSum(arr, n-1, sum-arr[n-1]);
// }

/**
 * @brief D.P. TABULATION TECHNIQUE
 * 
 * TIME COMPLEXITY: ⊝(n*sum)
 * AUXILIARY SPACE: ⊝(n*sum)
 *  
 *  Pseudo Polynomial as sum may vary to large extent!! 
 * @param arr 
 * @param n 
 * @param sum 
 * @return int 
 */
int subsetSum(int arr[], int n, int  sum)
{
    int dp[n+1][sum+1];

    for (int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for (int j=1; j<=sum; j++)
        dp[0][j] = 0;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            if (j<arr[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
    }
    
    return dp[n][sum];
}

int main()
{
    //EXAMPLE 1
    int arr[] = {10, 5, 2, 3, 6};
    int sum=8;

    //EXAMPLE 2
    // int arr[] = {1, 2, 3};
    // int sum=4;

    //EXAMPLE 3
    // int arr[] = {10, 20, 15};
    // int sum=37;

    //EXAMPLE 4
    // int arr[] = {10, 20, 15};
    // int sum=0;

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << subsetSum(arr, n, sum) << endl;

    return 0;
}