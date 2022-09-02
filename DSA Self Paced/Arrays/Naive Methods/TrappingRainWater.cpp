/**
 * @file TrappingRainWater.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 02:12AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
*/

int getWater(int *arr, int n)
{
    int res = 0;

    //as corner bars cannot store water so we traverse between then i=1 to i=n-2
    for (int i=1; i<n-1; i++)
    {
        //finding max bar on left of arr[i]
        int lmax = arr[i];
        for (int j=0; j<i; j++)
            lmax = max(lmax, arr[j]);
        
        //finding max bar on right of arr[i]
        int rmax = arr[i];
        for (int j=i+1; j<n; j++)
            rmax = max(rmax, arr[j]);
        
        //adding total water collected
        res += min(rmax, lmax) - arr[i];

    }

    return res;
}

int main()
{
    int arr[] = {3, 0, 1, 2, 5};
    // int arr[] = {2, 0, 2};
    // int arr[] = {1, 2, 3};
    // int arr[] = {3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << getWater(arr, n);

    return 0;
}