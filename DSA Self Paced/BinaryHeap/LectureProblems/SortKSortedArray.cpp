/**
 * @file SortKSortedArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief The Array is somewhat sorted and we have to fully sort it in an best optimised way
 * An element at index i will be present between the indexes i-k to i+k in the sorted array.
 * 
 * Example:
 *      Index:   0  1  2   3   4   5  
 * I/P: arr[] = {9, 8, 7, 18, 19, 17}
 *      K=2
 *      Index:   0  1  2   3   4   5 
 * O/P: arr[] = {8, 7, 9, 17, 18, 19}
 * 
 * I/P: arr[] = {10, 9, 7, 8, 4, 70, 50, 60}
 *      K=4
 * O/P: arr[] = {4, 7, 8, 9, 10, 50, 60, 70}
 * 
 * @version 0.1
 * @date 2022-11-19 06:06 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief TIME COMPLEXITY: O((n+k)logk)
 * 
 * @param arr 
 * @param n 
 * @param k 
 */
void kSortedArray(int arr[], int n, int k)
{
    //Since we are required to sort array in increasing order so we are using MinHeap
    priority_queue<int, vector<int>, greater<int>> pq;

    //O(k log k)
    for (int i=0; i<=k; i++)
        pq.push(arr[i]);
    
    int index=0;

    //O((n-k) log k)
    for (int i=k+1; i<n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    //O(klogk)
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
    
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // int arr[] = {9, 8, 7, 18, 19, 17};
    int arr[] = {10, 9, 7, 8, 4, 70, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    // int k=2;
    int k=4;

    printArray(arr, n);

    cout << endl;
    kSortedArray(arr, n, k);

    printArray(arr, n);

    return 0;
}