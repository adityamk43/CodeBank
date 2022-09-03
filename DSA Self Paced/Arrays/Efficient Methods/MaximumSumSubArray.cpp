/**
 * @file MaximumSumSubArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 01:52 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n)
*/

/*
    KADANE'S ALGORITHM
*/

int maxSumSubArrray(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i=1; i<n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }

    return res;
}

int main()
{
    // int arr[] = {1, -2, 3, -1, 2};
    // int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    // int arr[] = {-3, 8, -2, 4, -5, 6};
    int arr[] = {-1, -2, -3, -4};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSumSubArrray(arr, n);

    return 0;
}