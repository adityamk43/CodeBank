/**
 * @file MaximumDifference.cpp
 * @author ADITYA BHARDWAJ
 * @version 0.1
 * @date 2022-09-02 05:47 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊝(1)
*/

int maxDiff(int *arr, int n)
{
    int res = arr[1] - arr[0];
    int minValue = arr[0];

    for (int j = 1; j<n; j++)
    {
        res = max(res, arr[j]-minValue);
        minValue = min(minValue, arr[j]);
    }

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