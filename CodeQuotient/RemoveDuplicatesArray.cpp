/**
 * @file RemoveDuplicatesArray.cpp
 * @author ADITYA HBARDWAJ (you@domain.com)
 * @brief Write a function removeDuplicates() which receives a array as input and remove the duplicate elements from the array. After the function call, the array will contain a set of unique elements..

Suppose the array contains the following values:

{7, 7, 18, 18, 18, 18, 21, 39, 39, 42, 42, 42}
After a call to removeDuplicates(arr, size); , the array should store the following values:

{7, 18, 21, 39, 42}
If the array is empty or does not contain any duplicate values, calling your function should have no effect.

Input Format

First line contains the number of elements in array N.
and N integers will follow in next N lines.
Output Format

Print the non-duplicate elements of array.
Constraints

  1 <= N <= 10^5
 -(10^9) <= arr[i] <= 10^9
Sample Input

5  // No. of elements
1
1
2
3
3
Sample Output

1
2
3

 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>
// Include headers as needed

using namespace std;
void removeDuplicates(int arr[], int *size)
{
    // Write your code here

    int i = 1, j = 1;

    while (i < *size)
    {
        if (arr[i] != arr[i - 1])
            arr[j++] = arr[i];

        i++;
    }

    *size = j;
}

/* Include other headers as needed */
int main()
{
    int i, size = 0;
    // scanf("%d", &size);
    cin >> size;

    int arr[size];
    for (i = 0; i < size; i++)
        // scanf("%d", &arr[i]);
        cin >> arr[i];

    removeDuplicates(arr, &size);
    for (i = 0; i < size; i++)
        // printf("%d\n", arr[i]);
        cout << arr[i] << endl;

    return 0;
}