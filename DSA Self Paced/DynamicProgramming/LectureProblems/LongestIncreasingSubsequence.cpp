/**
 * @file LongestIncreasingSubsequence.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 *                                  LONGEST INCREASING SUBSEQUENCE (LIS)
 * As the name suggests, we need to find the length of the longest increasing subsequence from the given array.
 * 
 * EX:
 * {3, 4, 2, 8, 10}
 * 
 * O/P:
 * 4 (3 4 8 10)
 * 
 * The solution to this problem is quite tricky as compared to common D.P. problem we have solve but let's check it out!!
 * 
 * 
 * @version 0.1
 * @date 2022-12-19 09:47 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(n^2)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
// int LIS(int arr[], int n)
// {
//     int dp[n];
//     dp[0] = 1;

//     for (int i=1; i<n; i++)
//     {
//         dp[i]=1;

//         for (int j=0; j<i; j++)
//         {
//             if (arr[j] <= arr[i])
//                 dp[i] = max(dp[i], dp[j]+1);
//         }
//     }

//     int max_val = dp[0];

//     for (int i=0; i<n; i++)
//         max_val = max(max_val, dp[i]);

//     return max_val;
// }


//WE CAN OPTIMISED THE ABOVE FUNCTION USING BINARY SEARCH!!

/**
 * @brief BINARY SEARCH FOR CEILING (For more understanding refer to binary search video!!)
 * 
 * TIME COMPLEXITY: O(logn)
 * 
 * @param tail 
 * @param l 
 * @param r 
 * @param x 
 * @return int 
 */
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
 * @brief TIME COMPLEXITY: O(nlogn)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int LIS(int arr[], int n)
{
    int tail[n];

    tail[0] = arr[0];
    int len = 1;

    for (int i=1; i<n; i++)
    {
        if (arr[i] > tail[len-1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c=ceilingIdx(tail, 0, len-1, arr[i]);

            tail[c] = arr[i];
        }
    }

    return len;
}

//Extras (logn solution using vector!!)

int main()
{
    //EXAMPLE 1
    // int arr[] = {3, 4, 2, 8, 10};

    //EXAMPLE 2
    int arr[] = {3, 4, 2, 8, 10, 5, 1};

    //EXAMPLE 3
    // int arr[] = {4, 10, 6, 5, 8, 11, 2, 20};
    
    //EXAMPLE 4
    // int arr[] = {10, 20, 30};
    
    //EXAMPLE 5
    // int arr[] = {30, 20, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << LIS(arr, n) << endl;

    return 0;
}