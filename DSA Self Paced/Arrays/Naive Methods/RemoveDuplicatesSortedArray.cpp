/**
 * @file RemoveDuplicatesSortedArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 07:44PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    IDEA: we maintain a temporary array to store the distinct values from the original array. We use a variable as a index pointer for temporary array to store distinct values.

    We will always copy first element from original array to temporary array as first element is always unique.

    Then we start for index 1 that is second element of original array and check if that element is not equal to prev element and if it is not then we store that value in the temporary array and increment the pointer index of temporary variable.

    then after this we copy the elements in temp array to original array according to pointer index size and send the new size of the original array and the rest elements gets de allocated and only the unique elements are stored in the given/original array!!
*/



/*
    First loop will run ⊝(n) times
    second loop will run O(n) times

    So total time complexity is O(n) 

    TIME COMPLEXITY: O(n)
    SPACE COMPLEXITY/AUXILIARY SPACE: O(n)

*/

/*
    DRY RUN: 

            {10, 20, 20, 30, 30, 30, 30}
    temp =  {10, _, _, _, _, _, _}, res=1

    i=1: temp =  {10, 20, _, _, _, _, _}, res=2
    i=2: 
    i=3: temp =  {10, 20, 30, _, _, _, _}, res=3
    i=4:
    i=5:
        arr[] = {10, 20, 30, _, _, _}
*/

int removeDuplicates(int *arr, int n)
{
    int temp[n];

    temp[0] = arr[0];
    int res = 1;

    for (int i=1; i<n; i++)
    {
        if (arr[i-1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }

    for (int i=1; i<res; i++)
        arr[i] = temp[i];

    return res;
}

int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30, 30};
    // int arr[] = {10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    n = removeDuplicates(arr, n);

    cout << endl;
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}