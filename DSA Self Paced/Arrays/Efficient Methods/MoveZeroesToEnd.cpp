/**
 * @file MoveZeroesToEnd.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 09:17PM
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

void moveZeroesToEnd(int *arr, int n)
{
    int count = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i]!=0)
        {
            swap(arr[i], arr[count]);
            count++;
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