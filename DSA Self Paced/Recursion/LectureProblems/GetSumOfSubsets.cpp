/**
 * @file GetSumOfSubsets.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-25 10:11AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int countSumSubsets(int a[], int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0)? 1: 0;   
    }

    return countSumSubsets(a, n-1, sum) + countSumSubsets(a, n-1, sum - a[n-1]);
}

int main()
{
    // int a[] = {10, 15, 20};
    int a[] = {1, 3, 2, 4};
    int n = sizeof(a)/sizeof(a[0]);
    // int sum = 25;
    int sum = 4;
    cout << countSumSubsets(a, n, sum) << endl;
    return 0;
}