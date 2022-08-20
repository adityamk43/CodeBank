/**
 * @file Sort0s1s2sArray.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Sort an array of 0s, 1s and 2s star_border
Given an array containing only 0s, 1s and 2s. Sort the array in O(n) time i.e. process the array only once to do this sorting.

Input Format:

First Line will contain an integer N denoting the array size.
Second line contains N numbers (0, 1, 2) separated by space.
Output Format:

Print the sorted array.
Sample Input

6
0 0 2 0 1 2
Sample Output

0 0 0 1 2 2



 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;


/**
 * @brief Solution Approach 1

The naive approach will be to use any sorting algorithm and sort the given array.

Time Complexity: O(nlog(n))

Space Complexity: O(1)
 *
 */
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 0, 2, 0, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}



*/
/*I IMPLEMENTED WITH THE IDEA OF SOLUTION 2 AS GIVEN BELOW. THERE IS ALSO SOLUTION APPROACH 3 AT LAST TO REFER*/



/**
 * @brief Solution Approach 2

The given array only contains 0s, 1s and 2s, so why to use a conventional sorting algorithm. The idea is to count the number of 0s, 1s and 2s in the given array. Then store all the 0s in the beginning followed by all the 1s then all the 2s.

1. Keep three counters count0, count1, and count2, that will help us store the count of 0s, 1s and 2s respectively.

2. Traverse through the array and increase the count of count0 if the element is 0, increase the count of count1 if the element is 1 and increase the count of count2 if the element is 2.

3. Now again traverse the array and replace first count0 elements with 0, next count1 elements with 1 and next count2 elements with 2.

In this approach we have to do two traversals of the given array, and time complexity will be linear.

Time Complexity: O(n)

Space Complexity: O(1)
 *
 */

// Do not print anything, just sort the given array itself
void sorting012Array(int a[], int n)
{
    // Write your code here
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            count0++;

        if (a[i] == 1)
            count1++;

        if (a[i] == 2)
            count2++;
    }
    int j = 0;

    while (count0--)
        a[j++] = 0;

    while (count1--)
        a[j++] = 1;

    while (count2--)
        a[j++] = 2;
}
int main()
{
    int a[50];
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sorting012Array(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

/*
Solution Approach 3

In this approach we will perform only a single traversal on the given array arr[] and sort it. The idea is to shift all the 0s to the left side of the array and all the 2s to the right side of the array, because of this shifting all the 1s will automatically come between 0s and 2s, and the array will be sorted.

 Take 3 pointers i, j, k.
  ‘i’ pointer will help us place 0s towards the left side of the arr[] array, and it will be initialized with 0.
  ‘k’ pointer will help us place 2s towards the right side of the arr[] array, and it will be initialized with n-1(i.e. last index).
  ‘j’ pointer will help us traverse the array, and it will be initialized with 0.
Traverse the array from start to end until j <= k
If the element at j index is 0 then swap it with the element at i index and increment i, j by 1.
If the element at j index is 1 then simply ignore and move ahead(i.e. increment j by 1) as we are only interested in shifting 0s and 2s.
If the element at j index is 2 then swap it with the element at k index and decrement the value of k by 1, but in this case we will not update j because there may be a possibility that before swapping, the element at k index was also 2 so after swapping, again 2 will come at j index. Therefore to process the swapped element j will not be updated.
Time Complexity: O(n)

Space Complexity: O(1)
*/
/*

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
​
void sorting012Array(int a[], int n) {
  int i = 0, j = 0, k = n - 1;
  while (j <= k) {
    if (a[j] == 0) {
      swap( &a[j], &a[i]);
      i++;
      j++;
    }
    else if (a[j] == 1)
      j++;
    else if (a[j] == 2) {
      swap( &a[j], &a[k]);
      k--;
    }
  }
}
​
int main() {
  int arr[] = {1, 1, 0, 2, 0, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  sorting012Array(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}
*/