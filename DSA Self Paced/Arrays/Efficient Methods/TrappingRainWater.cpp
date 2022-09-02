/**
 * @file TrappingRainWater.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-09-03 02:33AM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(n)
*/

int getWater(int *arr, int n)
{
    int res = 0;

    // to store precomputed lmax and rmax for different bars in an= given array
    int lmax[n], rmax[n];

    // precomputing left max bar for every bars in arr
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(lmax[i - 1], arr[i]);

    // precomputing right max bar for every bars in arr
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(rmax[i + 1], arr[i]);

    // as corner bars cannot store water so we traverse between then i=1 to i=n-2
    for (int i = 1; i < n - 1; i++)
    {
        // adding total water collected
        res += min(rmax[i], lmax[i]) - arr[i];
    }

    return res;
}

int main()
{
    // int arr[] = {3, 0, 1, 2, 5};
    int arr[] = {5, 0, 6, 2, 3};
    // int arr[] = {2, 0, 2};
    // int arr[] = {1, 2, 3};
    // int arr[] = {3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getWater(arr, n);

    return 0;
}