/**
 * @file MoveNegElements.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Move the elements star_border
Write a function moveElements which receives an array of n elements (both positive and negative) as input and shift all the negative elements to the right side of the array while maintaining the original order of the positive and negative elements.

Note: consider 0 as a positive element.

Suppose the array contains the following values:

-6 7 13 10 -8 15 5 -9 2 -1

After a call to moveElements(arr, n); the array should store the following values:

7 13 10 15 5 2 -6 -8 -9 -1

Sample Input

10
-6 7 13 10 -8 15 5 -9 2 -1
Sample Output

7
13
10
15
5
2
-6
﻿-8
-9
﻿-1
Constraints : Don't use second array.


 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits.h>

using namespace std;

/**
 * @brief Solution Approach 1

The idea of this approach is to take an extra array that stores the final result.

Algorithm:

Take an auxiliary array res[] of the same size as that of the given array arr[], in which we will store the final result.
Take a pointer j initialised with 0, which will help us insert the elements in the res[] array.
Traverse the given array and whenever we find a non-negative element, insert that element in the res[] array at j index and increment j by 1.
Traverse the given array a second time and whenever we find a negative element, insert that element in the res[] array at j index and increment j by 1.
Using this approach we have shifted all the negative elements to the right side of the array while maintaining the original order of non-negative and negative elements.

Time Complexity: O(n)

Space Complexity: O(n)
 */
/*
#include <iostream>
using namespace std;

void moveElements(int arr[], int res[], int n){
   int j = 0;
   for (int i=0; i<n; i++){
       if (arr[i] >= 0)
           res[j++] = arr[i];
   }
   for (int i=0; i<n; i++){
       if (arr[i] < 0)
       res[j++] = arr[i];
   }
}

int main() {
   int arr[] = {-6, -9, 3, 4, -7, 2};
   int n = sizeof(arr) / sizeof(arr[0]);
   int res[n];
   moveElements(arr, res, n);
   for (int i = 0; i < n; i++)
       cout << res[i] << " ";
   return 0;
}
*/

/*
THIS WAS MY WAY OF IMPLEMENTATION BUT AS STATED IN THIS DESCRIPTION - "In this approach, it cannot be guaranteed that the final order of negative elements will be the same as that in the original array."
SO THIS SOLUTION IS NOT SUITED AS ONE OF THE CONSTRAINT WAS TO MAKE THE ARRAY HAVE THE SAME ORDER OF NEG AND POS VALUES BUT ONLY SHIFTING WAS TO BE DONE!!

SOLUTION APPROACH 3 IS THE BEST AND EASIEST ONE THROUGH MODIFIED INSERTION SORT ALGO BUT HAS O(n^2) T.C. SO NOT EFFICIENT AS COMPARED TO MY IMPLEMENTATION
*/

/*
Solution Approach 2 - Using Partitioning

In this solution approach, we will use the partitioning logic of quick sort considering 0 as the pivot element.

Take 2 pointers i, j.
‘i’ pointer will help us place all the non-negative elements towards the left side of the arr[] array, and it will be initialized with 0.
‘j’ pointer will help us iterating the arr[], and it will be initialized with 0.
Now ‘j’ pointer will start iterating the given array arr[], and whenever at index ‘j’ we find a non-negative(>=0) element, we swap that element with the element at ‘i’ index and increment the value of ‘i’ by 1.
After ‘j’ completes the iteration, the given array arr[] will be partitioned and all negatives will be shifted to the right and all the non-negative elements to the left.
Note: In this approach, it cannot be guaranteed that the final order of negative elements will be the same as that in the original array.

Time Complexity: O(n)

Space Complexity: O(1)
*/

/*

// To swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int *partition(int array[], int n, int pivot, int pivot_index)
{
    int i = -1;
    int j;

    for (j = 0; j <= (n - 1); j++)
    {
        if (array[j] >= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    // swap(&array[i + 1], &array[pivot_index]);
    return array;
}

void moveElements(int arr[], int n)
{
    // Write your code here
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min && arr[i] >= 0)
        {
            min = arr[i];
            min_index = i;
        }
    }

    arr = partition(arr, n, min, min_index);
}

int main()
{
    int i, size = 0;
    scanf("%d", &size);

    int arr[size];
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    moveElements(arr, size);
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);

    return 0;
}

*/
/**
 * @brief Solution Approach 3 - Using Modified Insertion Sort

In this approach, we will use a modified insertion sort to solve the problem.

Algorithm-

Iterate the given array from 1 to n-1.
If the current element is negative, do nothing.
If the current element arr[i] is non-negative(>=0), we insert it into sequence arr[0..i-1] such that all negative elements in arr[0..i-1] are shifted one position to their right and arr[i] is inserted at index of first negative element.
Time Complexity: O(n2)

Space Complexity: O(1)
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void moveElements(int arr[], int n)
{
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j - 1] < 0)
                    swap(&arr[j], &arr[j - 1]);
                else
                    break;
            }
        }
    }
}
int main()
{
    int i, size = 0;
    scanf("%d", &size);

    int arr[size];
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    moveElements(arr, size);
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);

    return 0;
}
