/**
 * @file CountOccurence.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Given a sorted list of integers with duplicates, find the count of a given number K in that list in O(log n) time.

Input

First line of input will contain a positive integer T = number of test cases. Each test case will contain 2 lines.
First line of each test case will contain two number N = number of elements in list and K separated by space.
Next line will contain N space separated integers.
Constraints

  1 <= N <= 10^5
 -(10^9) <= arr[i], K <= (10^9)
Output

For each test case, print on a single line, the count of number K in this list.
Sample Input

3  // Test Cases
10 5  // N K (testcase 1)
1 2 2 5 5 5 7 7 7 8
10 1  // N K (testcase 2)
1 1 1 1 1 1 1 2 2 3
20 2  // N K (testcase 3)
1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4
Sample Output

3
7
5
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int firstOccurence(int arr[], int n, int k)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == k)
        {
            if (arr[mid - 1] != k)
                return mid;

            if (arr[mid - 1] == k && mid - 1 >= left)
                right = mid - 1;
        }
        else if (k < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int lastOccurence(int arr[], int n, int k)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == k)
        {
            if (arr[mid + 1] != k)
                return mid;

            if (arr[mid + 1] == k && mid + 1 <= right)
                left = mid + 1;
        }
        else if (k < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int CountOccurence(int arr[], int n, int k)
{
    int f = firstOccurence(arr, n, k);
    int l = lastOccurence(arr, n, k);

    if (f != -1)
        return (l-f+1);
    
    return 0;
}

int main()
{
    int T, n, k, arr[30];

    cin >> T;

    while (T > 0)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << CountOccurence(arr, n, k) << endl;

        T--;
    }

    return 0;
}