/**
 * @file SlidingWindowTechnique.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 06:00 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    MAXIMUM SUM OF K CONSECUTIVE ELEMENTS

    (THIS IS NOT A SLIDING WINDOW TECHNIQUE, BUT THE NAME OF FILE IS GIVEN SO THAT WE CAN KNOW NAIVE APPROACH OF SOLVING THIS QUESTION WHICH CAN BE SOLVED USING SLIDING WINDOW FOR ADAPTING EFFICIENT APPROACH!!)
*/

/*
    TIME COMPLEXITY: O(n*k)
    AUXILIARY SPACE: O(1)
*/

/*
    DRY RUN: 
        [10, 5, -2, 20, 1]
        k=3

        i=0: curr = 13, res = 13
        i=1: curr = 23, res = 23
        i=2: curr = 19
*/

int maxSum(int arr[], int n, int k)
{
    int res = INT_MIN;

    for (int i=0; i+k-1<n; i++)
    {
        int curr_sum = 0;

        for (int j=0; j<k; j++)
        {
            curr_sum += arr[i+j];
            res = max(res, curr_sum);
        }
    }

    return res;
}

int main()
{
    int arr[] = {10, 5, -2, 20, 1};
    // int arr[] = {1, 8,30, -5, 20, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << maxSum(arr, n, k) << endl;

    return 0;
}