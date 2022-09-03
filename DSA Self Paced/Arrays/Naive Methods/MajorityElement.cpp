/**
 * @file MajorityElement.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 07:22 PM
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
    arr[] = {8, 7, 6, 8, 6, 6, 6, 6}

    n=8

    i=0: count = 2 (for 8)
    i=1: count = 1 (for 7)
    i=2: count = 5 (for 6)

    O/P: 2 (first occuring index of 6)
*/

int findMajority(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        int count = 1;

        for (int j=i+1; j<n; j++)
        {
            if (arr[i] == arr[j])
                count ++;
        }

        if (count > n/2)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};
    // int arr[] = {3, 7, 4, 7, 7, 5};

    int n =sizeof(arr)/sizeof(arr[0]);

    int index = findMajority(arr, n);

    cout << "Index: " << index << endl;
    
    if (index >= 0)
        cout << "Element: " << arr[index] << endl;


    return 0;
}