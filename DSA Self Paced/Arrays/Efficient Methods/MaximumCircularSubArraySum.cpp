/**
 * @file MaximumCircularSubArraySum.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-09-03 07:20 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n)
*/

int kadane(int a[], int n)
{
    int res = a[0];
    int curr_sum = a[0];

    for (int i = 1; i < n; i++)
    {
        curr_sum = max(curr_sum + a[i], a[i]);
        res = max(res, curr_sum);
    }

    return res;
}

int maxCircularSubArraySum(int a[], int n)
{
    int max_normal = kadane(a, n);

    if (max_normal < 0)
        return max_normal;

    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += a[i];
        a[i] = -a[i];
    }

    int circular_max = arr_sum + kadane(a, n);

    return max(max_normal, circular_max);
}

int main()
{
    int arr[] = {5, -2, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxCircularSubArraySum(arr, n) << endl;

    return 0;
}