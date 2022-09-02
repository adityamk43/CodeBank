/**
 * @file FrequenciesInSortedArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-02 06:14 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊖(n)
*/

/*
    NOTE: Frequencies in Unsorted Array better approach is covered in different track as normally it will take nlogn time to sort and then theta(n) means Overall O(nlogn) time to find frequencies for unsorted here.
*/

void printFreq(int *arr, int n)
{
    int freq = 1, i=1;

    while (i<n)
    {
        while (i<n && arr[i]==arr[i-1])
        {
            freq++;
            i++;
        }

        cout << arr[i-1] << " " << freq << endl;
        freq=1;
        i++;
    }

    if (n==1 || arr[n-1]!=arr[n-2])
        cout << arr[n-1] << " " << 1 << endl;

}

int main()
{
    int arr[] = {10, 10, 10, 30, 30, 40};
    // int arr[] = {10, 10, 10, 25, 30, 30};
    // int arr[] = {40, 50, 50, 50};
    // int arr[] = {10, 20, 30};
    // int arr[] = {10, 10, 10, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    printFreq(arr, n);

    return 0;
}