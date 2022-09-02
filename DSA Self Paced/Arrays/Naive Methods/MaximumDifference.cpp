/**
 * @file MaximumDifference.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-02 05:24 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(n^2)
*/

int maxDiff(int *arr, int n)
{
    int res = arr[1] - arr[0];
    for (int i=0; i<n; i++)
        for (int j = i+1; j<n; j++)
            res = max(res, arr[j]-arr[i]);

    return res;
}

int main()
{
    int arr[] = {2,3,10,6,4,8,1};
    // int arr[] = {10, 20, 30};
    // int arr[] = {30, 10, 8, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxDiff(arr, n);

    return 0;
}