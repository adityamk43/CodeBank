/**
 * @file xor.cpp
 * @author Aditya Bhardwaj
 * @brief To find the odd occuring number. (Quiz Bit Magic) DSA Self-Paced
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int fun(int arr[], int n)
{
    int x = arr[0];

    for (int i=1; i<n; i++)
    {
        x ^= arr[i];
    }

    return x;
}

int main()
{
    int arr[] = {9,12,2,11,2,2,10,9,12,10,9,11,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << fun(arr,n);
    return 0;
}