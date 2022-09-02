/**
 * @file MaxConsecutiveOnes.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 03:06 AM
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

int maxConsecutiveOnes(bool *arr, int n)
{
    int res = 0;

    for (int i=0; i<n; i++)
    {
        int curr = 0;

        for (int j=i; j<n; j++)
        {   if (arr[j] == 1)
                curr++;
            else
                break;
        }

        res = max(res, curr);
    }

    return res;

}

int main()
{
    // bool arr[] = {0, 1, 1, 0, 1, 0};
    bool arr[] = {0, 1, 1, 0, 1, 1, 1};
    // bool arr[] = {1, 1, 1, 1};
    // bool arr[] = {0, 0, 0};
    // bool arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxConsecutiveOnes(arr, n);

    return 0;
}