/**
 * @file SubarrayWithGivenSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 07:17 PM
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

/*
    USING SLIDING WINDOW TECHNIQUE
*/


bool isSubArr(int arr[], int n, int sum)
{
    int s=0, curr_sum=0;

    for (int e=0; e<n; e++)
    {
        curr_sum += arr[e];

        while (curr_sum > sum)
        {
            curr_sum -= arr[s];
            s++;
        }

        if (curr_sum == sum)
            return true;
    }

    return false;
}

int main()
{
    // int arr[] = {3, 2, 0, 4, 7};
    int arr[] = {4, 8, 12, 5};
    // int arr[] = {2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int sum = 6;
    int sum = 17;
    // int sum = 3;

    if (isSubArr(arr, n, sum))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;    

    return 0;
}