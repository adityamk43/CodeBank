/**
 * @file LongestEvenOddSubArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 04:04 PM
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
    BASED ON KADANE'S ALGORITHM
*/

int maxEvenOddSubarray(int arr[], int n)
{
    int res = 1;
    int curr = 1;

    for (int i=1; i<n; i++)
    {
        
        if ((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0))
            curr++;
        else
            curr = 1;

        res = max(res, curr);
    }

    return res;
}

int main()
{
    // int arr[] = {10, 12, 14, 7, 8};
    int arr[] = {5, 10, 20, 6, 3, 8};
    // int arr[] = {7, 10, 13, 14};
    // int arr[] = {10, 12, 8, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxEvenOddSubarray(arr, n) << endl;

    return 0;
}