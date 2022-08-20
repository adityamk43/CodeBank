/**
 * @file MaxAND.cpp
 * @author Aditya Bhardwaj
 * @brief finding MaxAND value pair in a given array
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i=0; i<n; i++)
    {
        if ((pattern & arr[i]) == pattern)
            count++;
    }

    return count;
}

int maxAND(int arr[], int n)
{
    int res=0;
    for (int bit=31; bit>=0; bit--)
    {
        int count = checkBit(res | (1<<bit), arr, n);

        if (count>=2)
            res |= 1<< bit;
    }
    return res;
}

int main()
{
    int arr[] = {4,13,12,16};
    int n = sizeof(arr)/sizeof(int);
    cout << maxAND(arr, n) << endl;

    return 0;
}