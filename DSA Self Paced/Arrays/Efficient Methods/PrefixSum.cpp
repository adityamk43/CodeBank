/**
 * @file PrefixSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-05 05:10 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: O(1)
*/

//defining constant size of prefix array makes AUXILIARY SPACE O(1)
int prefix_sum[1000];

//precomputation of prefix sums requires O(n) time
void precomputePrefixSum(int arr[], int n)
{
    prefix_sum[0] = arr[0];

    for (int i=1; i<n; i++)
        prefix_sum[i] = arr[i] + prefix_sum[i-1];
}

//returning prefix sum of given range in O(1) time due to the pre computed prefix sums
int getSum(int left, int right)
{
    if (left != 0)
        return prefix_sum[right] - prefix_sum[left-1];
    else
        return prefix_sum[right];
}

int main()
{
    int arr[] = {2, 8, 3, 9, 6, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    precomputePrefixSum(arr, n);

    cout << getSum(0, 2) << endl;
    cout << getSum(1, 3) << endl;
    cout << getSum(2, 6) << endl;

    return 0;
}