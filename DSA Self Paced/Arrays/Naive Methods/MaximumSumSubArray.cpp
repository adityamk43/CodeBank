/**
 * @file MaximumSumSubArray.cpp
 * @author ADITYA BHARDWAJ
 * @version 0.1
 * @date 2022-09-03 01:39 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
*/

/*
    DRY RUN: 

    {1, -2, 3, -1, 2}

    res = 1

    i=0:
        curr = 0
        curr = 1
        curr = 1-2 = -1
        curr = -1 + 3 = 2, res = 2
        curr = 2 - 1 = 1
        curr = 1 + 2 = 3, res = 3
    
    i=1: 
        curr = 0
        curr = -2
        curr = -2 + 3 = 1
        curr = 1 - 1 = 0
        curr = 0 + 2 = 2
    
    .
    .
    .

    i=2
        curr = 0
        curr = 3
        curr = 3 - 1 = 2
        curr = 2 + 2 = 4, res = 4 (ANSWER)
    .
    .
    .
    so on..
*/

int maxSumSubArrray(int arr[], int n)
{
    int res = arr[0];
    
    for (int i=0; i<n; i++)
    {
        int curr = 0;

        for (int j=i; j<n; j++)
        {
            curr += arr[j];

            res = max(res, curr);
        }
    }

    return res;
}

int main()
{
    // int arr[] = {1, -2, 3, -1, 2};
    // int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    int arr[] = {-3, 8, -2, 4, -5, 6};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSumSubArrray(arr, n);

    return 0;
}