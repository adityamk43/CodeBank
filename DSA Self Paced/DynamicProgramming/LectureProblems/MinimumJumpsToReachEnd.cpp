/**
 * @file MinimumJumpsToReachEnd.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given an array where every value represents the maximum number of jumps you can make from this particular point(index) in the array.
 * 
 * We need to find the Maximum Jumps we can make to reach the End of the array.
 * 
 * Ex:
 * arr[] = {3, 4, 2, 1, 2, 1}
 * O/P: 2 (3->4->1)
 *     i = 0  1  5
 * 
 * arr[] = {4, 1, 5, 3, 1, 3, 2, 1, 8}
 * O/P: 3
 * 
 * a) (4->3->2->8)
 * i=  0  3  6  8
 * OR
 * b) (4->3->3->8)
 * i=  0  3  5  8
 * 
 * c) (4->5->1->8)
 * i=  0  2  7  8
 * 
 * d) (4->5->3->8)
 * i=  0  2  5  8
 * 
 * Above four produces minimum jumps for this case i.e., 3!
 * 
 * @version 0.1
 * @date 2022-12-20 07:19 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION WITH OVERLAPPINGS FUNCTION CALLS
 * 
 * TIME COMPLEXITY: EXPONENTIAL O(2^n) (Either you make a jump or not)
 * AUXILIARY SPACE: O(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
// int maxJumpsToEnd(int arr[], int n)
// {
//     if (n==1)
//         return 0;
    
//     int res=INT_MAX;

//     for (int i=0; i<=n-2; i++)
//     {
//         if (i+arr[i] >= n-1)
//         {
//             int sub_res = maxJumpsToEnd(arr, i+1);

//             if (sub_res != INT_MAX)
//             {
//                 res = min(res, 1+sub_res);
//             }
//         }
//     }

//     return res;
// }

/**
 * @brief D.P. TABULATION
 * 
 * TIME COMPLEXITY: ⊝(n^2)
 * AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int maxJumpsToEnd(int arr[], int n)
{
    int dp[n];

    dp[0]=0;

    for (int i=1; i<n; i++)
        dp[i] = INT_MAX;
    
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[j]+j>=i)
            {
                if (dp[j]!=INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }

    return dp[n-1];
}

int main()
{
    //EXAMPLE 1
    // int arr[] = {3, 4, 2, 1, 2, 1};
    
    //EXAMPLE 2
    int arr[] = {4, 1, 5, 3, 1, 3, 2, 1, 8};
    
    //EXAMPLE 3
    // int arr[] = {};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxJumpsToEnd(arr, n) << endl;

    return 0;
}