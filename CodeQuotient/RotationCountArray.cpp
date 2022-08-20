/**
 * @file RotationCountArray.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Given a circularly sorted array of N integers, find the minimum number of rotations performed on some sorted array to create this given array.

Assume there are no duplicate elements in the array, and the rotation is in anti-clockwise direction.

Expected Time Complexity: O(log(N))

Expected Space Complexity: O(1)

Input format:

First line of input will contain a number T = number of test cases. Each test case will contain 2 lines.
First line will contain a number N = number of elements in the array.
Next line will contain N space separated integers.
Complete the function int rotationCount(int array[], int size) which will receive the array and size of the array as input and return how many times the sorted array is rotated. Function should return 0 if the array is not rotated.
Output format:

Print one line of output for each test case with the minimum number of rotations for the given array.
Constraints:

  1 <= T <= 10
  1 <= N <= 50
 -1000 <= arr[i] <= 1000
Sample Input

2  // No. of test cases
6
15 18 3 4 6 12
6
1 2 3 4 5 6
 Sample Output

2
0
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

/**
 * @brief Solution Approach 2 - Using Binary Search
 
The idea is to use a modified binary search to find the minimum element index. The minimum element in the rotated sorted array has one special property that both its previous and next element are greater than it, therefore it is also known as the pivot element. No other element will have this property except the pivot element.

In case the pivot is the last element, then the first element will be considered its next element because the given array is circularly rotated. Similarly, if the pivot is the first element, then the last element will be considered its previous element.

In binary search, we always check the middle element and based on some conditions discard the left or right half of our search space. In this solution also If we do not find the pivot element at the middle index, then we need some conditions to continue searching in the left subarray or right subarray. Those conditions are:

If the middle element is smaller than the rightmost element of our search space, then the pivot element lies in the left half.
Else the pivot element lies in the right half.
Time Complexity: O(log(n))

Space Complexity: O(1)
 * 
 */
int rotationCount(int arr[], int size)
{
    // Write your code here
    int left = 0;
    int right = size-1;
    int prev, next;
    int mid;

    while (left<=right)
    {
        mid = left + (right - left)/2;
        prev = (mid-1+size)%size;
        next = (mid+1)%size;

        if (arr[mid] < arr[next] && arr[mid] < arr[prev])
            return mid;
        else if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid - 1;
            
    }

    return 0;
}

int main()
{
    int T, i, size = 0;
    cin >> T;

    while (T--)
    {
        cin >> size;

        int arr[size];
        for (i = 0; i < size; i++)
            cin >> arr[i];

        cout << rotationCount(arr, size) << endl;
    }
    return 0;
}
