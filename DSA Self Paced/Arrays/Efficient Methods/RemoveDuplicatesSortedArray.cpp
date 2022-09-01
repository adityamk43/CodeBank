/**
 * @file RemoveDuplicatesSortedArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 08:12PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    This not only saves space but also saves extra work that was required to copy the elements back from temporary to original array.

    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(1)
*/


int removeDuplicates(int *arr, int n)
{
    //tells the current index also and this also tells you the current size of the result also
    int res = 1;

    for (int i=1; i<n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }

    return res;
}

int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30, 30};
    // int arr[] = {10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    n = removeDuplicates(arr, n);

    cout << endl;
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}