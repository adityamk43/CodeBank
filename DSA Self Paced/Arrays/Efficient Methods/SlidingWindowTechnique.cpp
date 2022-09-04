/**
 * @file SlidingWindowTechnique.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 06:18 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    MAXIMUM SUM OF K CONSECUTIVE ELEMENTS

    (SLIDING WINDOW TECHNIQUE)
*/

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: O(1)
*/


int maxSum(int arr[], int n, int k)
{
    int curr_sum = 0;

    for (int i=0; i<k; i++)
        curr_sum += arr[i];
    
    int res = curr_sum;

    for (int i=k; i<n; i++)
    {
        curr_sum += arr[i] - arr[i-k];
        res = max(res, curr_sum);
    }

    return res;
}

int main()
{
    // int arr[] = {10, 5, -2, 20, 1};
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int k = 3;
    int k = 4;

    cout << maxSum(arr, n, k) << endl;

    return 0;
}