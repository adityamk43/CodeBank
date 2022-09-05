/**
 * @file EqulibriumPoint.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-05 05:23 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(1)
*/

//This program is done in O(1) AUXILIARY SPACE but we could have used 2 arrays for l_sum and r_sum computations to store prefix sum and suffix sum respectively but these arrays could have caused O(n) AUXILIARY SPACE. Thus, this solution solves the problem of TIME COMPLEXITY as well as AUXILIARY SPACE!!!

bool isEquilibriumPoint(int arr[], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];

    int l_sum = 0;
    
    for (int i=0; i<n; i++)
    {
        if (l_sum == sum - arr[i])
            return true;
        
        l_sum += arr[i];
        sum -= arr[i];
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