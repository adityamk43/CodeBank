/**
 * @file EqulibriumPoint.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-05 05:18 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
    AUXILIARY SPACE: O(1)
*/

bool isEquilibriumPoint(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        int l_sum = 0, r_sum = 0;

        for (int j=0; j<i; j++)
            l_sum += arr[j];

        for (int j=i+1; j<n; j++)
            r_sum += arr[j];

        if (l_sum == r_sum)
            return true;
    }

    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    // int arr[] = {4, 2, -2};
    // int arr[] = {-2, 2, 4};
    // int arr[] = {4, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    if (isEquilibriumPoint(arr, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}