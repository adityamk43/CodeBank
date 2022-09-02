/**
 * @file MaxConsecutiveOnes.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 03:17 AM
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

/*
    NOTE: More Efficient Solution using Bitwise to do in O(logn) time.
    GFG Problem in Bitwise Track**
*/

int maxConsecutiveOnes(bool *arr, int n)
{
    int res = 0, curr = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i] == 0)
            curr = 0;
        else
        {
            curr++;
            res = max(res, curr);
        }
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