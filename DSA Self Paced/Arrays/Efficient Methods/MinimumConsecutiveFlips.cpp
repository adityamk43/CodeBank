/**
 * @file MinimumConsecutiveFlips.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 05:46 PM
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

void printFlipGroups(bool arr[], int n)
{
    //starting from i=1 since 1st element (0th index element) is always considered as a first group
    for (int i=1; i<n; i++)
    {
        if (arr[i] != arr[i-1])
        {
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << (i-1) << endl;
        }
    }

    //if last element is not equal to first element eg: {0, 0, 1, 1, 0, 0, 1, 1, 0, 1}
    if (arr[n-1] != arr[0])
        cout << (n-1) << endl;
}

int main()
{
    // bool arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0};
    bool arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    // bool arr[] = {1, 1, 0, 0, 0, 1};
    // bool arr[] = {0, 0, 0};
    // bool arr[] = {1, 1, 1};
    // bool arr[] = {0, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    printFlipGroups(arr, n);

    return 0;
}