/**
 * @file LeadersInAnArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-02 12:03AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
*/

void leaders(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bool flag = false;

        for (int j=i+1; j<n; j++)
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }

        if (flag == false)
            cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 10, 6, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    leaders(arr, n);

    return 0;
}