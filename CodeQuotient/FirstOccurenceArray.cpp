/**
 * @file FirstOccurenceArray.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Given a sorted list of integers, find the position of first occurrence of a given number K in the list in O(log n) time.

Input Format:

First line of input will contain a positive integer T = number of test cases.
Each test case will contain the following two lines:
  First line will contain two positive integer N = number of elements in list and K.
  Second line will contain N space separated integers in increasing order.
Constraints:

  1 <= N <= 10^5
 -(10^9) <= arr[i], K <= (10^9)
Output Format:

For each test case, print on a single line the index of first occurrence of K in the list on 0-based index. Print -1 if you cannot find K in the list.
Sample Input

3  // Test Cases
10 4  // N K (testcase 1)
1 2 4 4 4 4 5 8 9 10
15 7  // N K (testcase 2)
1 2 3 3 5 6 7 7 7 7 7 8 8 8 8
9 1   // N K (testcase 3)
-5 -4 -3 -2 -1 0 0 0 1
Sample Output

2
6
8
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

int FirstOccurence(int arr[], int n, int k)
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

        cout << FirstOccurence(arr, n, k) << endl;

        T--;
    }

    return 0;
}