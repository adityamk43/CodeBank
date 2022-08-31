/**
 * @file ArrayIsSorted.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 02:20AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
    
    Best Case: When first two elements are not in ordered
                ⊖(1)

    Worst Case: When the given array is sorted
                ⊖(n^2)

*/

/*
    DRY RUN:
    {7, 20, 30, 10}

    i=0: Ignore

    i=1: 
        j=3: return false
*/

bool isSorted(int *arr, int n)
{
    for (int i=0; i<n; i++)
        for (int j = i+1; j<n; j++)
            if (arr[j] < arr[i])
                return false;

    return true;
}

int main()
{
    // int arr[] = {7, 20, 30, 10};
    // int arr[] = {10, 5, 20, 40};
    int arr[] = {1, 2, 3, 4};

    cout << isSorted(arr, 4);

    return 0;
}