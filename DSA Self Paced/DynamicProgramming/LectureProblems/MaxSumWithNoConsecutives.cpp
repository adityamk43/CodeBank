/**
 * @file MaxSumWithNoConsecutives.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given an array, we need to find the maximum sum in an array such that elements that are considered for maximum sum are not contiguous to each other in the given array.
 * 
 * Idea is same as normal D.P. or recursive solutions. Either we consider specific element in the sum or 
 * doesn't consider that element in the sum.
 * 
 * @version 0.1
 * @date 2022-12-24 11:08 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief 1.) PLAIN RECURSIVE SOLUTION WITH OVERLAPPINGS
 * 
 * TIME COMPLEXITY: O(2^n) Exponential
 * 
 * T(n) = T(n-1) + T(n-2) + ⊝(1)
 *      = O(2^n)
 * It is same as Fibonacci Recurrence!!
 * 
 * NOTE: THE ACTUAL UPPER BOUND IS ALSO EXPONENTIAL. IT'S GOLDEN RATIO^N
 * 
 * 1.6180 is also called the golden ratio. You can read more about golden ratio here: Golden Ratio in Maths(https://www.mathsisfun.com/numbers/golden-ratio.html)
 * 
 * GOLDEN RATIO: The golden ratio (symbol is the Greek letter "phi" shown at left)
is a special number approximately equal to 1.618

It appears many times in geometry, art, architecture and other areas.
 * 
 * AUXILIARY SPACE: O(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
// int maxSum(int arr[], int n)
// {
//     //if there is 1 element in the array, we return that.
//     if (n==1)
//         return arr[0];

//     //if there is only 2 element then we return max of it as we can't add two consecutive elements
//     if (n==2)
//         return max(arr[0], arr[1]);

//     return max(
//         //not consider last element
//         maxSum(arr, n-1),
//         //consider last element and do recursion for n-2 elements as we can add consecutive element so we leave (n-2)th element. and we can be sure of adding arr[n-1] since, we know that there are no negative elements in the array.
//         maxSum(arr, n-2)+arr[n-1]
//     );   
// }

/**
 * @brief 2.) D.P. TABULATION TECHNIQUE: ⊝(n) Auxiliary Space approach!!
 * 
 * TIME COMPLEXITY: ⊝(n)
 * AUXILIARY SPACE: ⊝(n)
 * 
 * IMPORTANTNOTE: We can reduce the Extra Space(Auxiliary Space) to constant(⊝(1)). Since, we know that this algorithm is similar to Fibonacci solution. So, like we did in optimised Fibonacci approach, here also by following that, we can reduce the Auxiliary Space to ⊝(1).
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
// int maxSum(int arr[], int n)
// {
//     if (n==1)
//         return arr[0];
            
//     int dp[n+1];

//     //we don't need to fill dp[0], since index of dp array are length of the array and not indices!!
//     dp[1] = arr[0];
//     dp[2] = max(arr[0], arr[1]);

//     for (int i=3; i<=n; i++)
//         dp[i] = max(dp[i-1], dp[i-2]+arr[i-1]);

//     return dp[n];
// }

/**
 * @brief  3.) D.P. TABULATION TECHNIQUE: ⊝(1) Auxiliary Space approach!!
 * 
 * TIME COMPLEXITY: ⊝(n)
 * AUXILIARY SPACE: ⊝(1)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int maxSum(int arr[], int n)
{
    if (n==1)
        return arr[0];

    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);

    //if given n=2, then we can return res with this value otherwise we go into the below for loop starting from i=3 which is length of the given array
    int res = prev;

    for (int i=3; i<=n; i++)
    {
        res = max(prev, prev_prev + arr[i-1]);
        prev_prev = prev;
        prev = res;
    }

    return res;
}

int main()
{
    //EXAMPLE 1
    // int arr[] = {10, 5, 15, 20};

    //EXAMPLE 2
    int arr[] = {1, 10, 2};

    //EXAMPLE 3
    // int arr[] = {8, 7, 6, 10};

    //EXAMPLE 4
    // int arr[] = {10, 5, 15, 20, 2, 30};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << maxSum(arr, n) << endl;

    return 0;
}