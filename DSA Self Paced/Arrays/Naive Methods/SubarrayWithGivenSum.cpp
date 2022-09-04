/**
 * @file SubarrayWithGivenSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 06:39 PM
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
    DRY RUN:

    sum = 6
    {3, 2, 0, 4, 7}

    i=0: j=0: curr = 3
        j=1: curr = 5 
        j=2: curr = 5 
        j=3: curr = 9 
        j=4: curr = 16
        
    i=1: j=1: curr = 2
        j=2: curr = 2 
        j=3: curr = 6

        return true
*/


bool isSubArr(int arr[], int n, int sum)
{
    for (int i=0; i<n; i++)
    {
        int curr_sum = 0;

        for (int j=i; j<n; j++)
        {
            curr_sum += arr[i];

            if (curr_sum == sum)
                return true;
        }
    }

    return false;
}

int main()
{
    int arr[] = {3, 2, 0, 4, 7};
    // int arr[] = {2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    // int sum = 3;

    if (isSubArr(arr, n, sum))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;    

    return 0;
}