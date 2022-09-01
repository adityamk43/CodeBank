/**
 * @file MoveZeroesToEnd.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 08:56 PM
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
    {10, 5, 0, 0, 8, 0, 9, 0}

    i=0: 
    i=1:
    i=2: swap(arr[i],arr[j])
        j=4
        {10, 5, 0, 0, 8, 0, 9, 0}
        TO
        {10, 5, 8, 0, 0, 0, 9, 0}
    i=3:swap(arr[i],arr[j])
        j=6
        {10, 5, 8, 0, 0, 0, 9, 0}
        TO
        {10, 5, 8, 9, 0, 0, 0, 0}
    i=4:
    i=5:
    i=6:
    i=7:
*/

void moveZeroesToEnd(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i]==0)
        {
            for (int j=i+1; j<n; j++)
            {
                if (arr[j]!=0)
                    swap(arr[i], arr[j]);
            }
        }
    }
}


int main()
{
    int arr[] = {8, 5, 0, 10, 0, 20};
    // int arr[] = {10, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    moveZeroesToEnd(arr, n);

    cout << endl;

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}