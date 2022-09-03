/**
 * @file MaximumCircularSubArraySum.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 04:58 PM
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
    
    arr[] = {5, -2, 3, 4}
    res = 5

    i=0: curr_max = 10, res = 10
    i=1: curr_max = 10
    i=2: curr_max = 12, res = 12
    i=3: curr_max = 10
*/

int maxCircularSubArraySum(int arr[], int n)
{
    int res = arr[0];
    int curr_max = arr[0];

    for(int i=0; i<n; i++)
    {
        int curr_sum = arr[i];

        for (int j=1; j<n; j++)
        {
            //for getting all circular subarrays (also normal subarrays)
            int index = (j+i)%n;

            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }

        res = max(res, curr_max);

    }

    return res;
}

int main()
{
    int arr[] = {5, -2, 3, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxCircularSubArraySum(arr, n) << endl;

    return 0;
}