/**
 * @file OddOccuringMissingNumber.cpp
 * @author Aditya Bhardwaj
 * @brief Finding missing number between range of 1 and n+1 in a given array using one odd occuring xor technique. Every number in arr should be present exactly once between range 1 to n+1 (arr[1...n+1])
 * @version 0.1
 * @date 2022-08-19 1:58 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int MissingNumber(int n, int arr[])
{
    int res=0;
    for (int i=0; i<n; i++)
        res = res ^ arr[i] ^ (i+1);

    return res ^ (n+1) ;
}


int main()
{
    int n;
    cout << "Enter size of an array: " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array elements: " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int res = MissingNumber(n, arr);

    cout << res;

    return 0;
}