/**
 * @file LongestEvenOddSubArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 03:48 PM
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

    arr[] = {5, 10, 20, 6, 3, 8}
    res = 1

    i=0: curr=2, res=2
    i=1: curr=1
    i=2: curr=1
    i=3: curr=3, res=3
    i=4: curr=2
    i=5: curr=1
*/

int maxEvenOddSubarray(int arr[], int n)
{
    int res = 1;

    for (int i=0; i<n; i++)
    {
        int curr = 1;

        for (int j=i+1; j<n; j++)
        {
            if ((arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j]%2!=0 && arr[j-1]%2==0))
                curr++;
            else
                break;
        }

        res = max(res, curr);
    }

    return res;
}

int main()
{
    // int arr[] = {10, 12, 14, 7, 8};
    int arr[] = {5, 10, 20, 6, 3, 8};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxEvenOddSubarray(arr, n) << endl;

    return 0;
}