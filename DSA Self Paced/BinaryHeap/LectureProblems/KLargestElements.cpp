/**
 * @file KLargestElements.cpp
 * @author ADITYA BHARDWAJ
 * @brief Print K Largest Elements
 * @version 0.1
 * @date 2022-11-19 07:18 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * @brief Method 1(Using MaxHeap)
 * 
 * TIME COMPLEXITY: O(n + klogn)
 * 
 * BEST: O(n + logn)
 * WORST: (n + nlogn)
 * 
 */

/**
 * @brief TIME COMPLEXITY: O(k + (n-k)logk)
 * 
 * BEST: O(n)
 * WORST: O(n + logn)
 * 
 * SO, For Finding K Largest Elements MinHeap performs better than MaxHeap and is more optimised in terms of Time Complexity
 * 
 * @param arr 
 * @param n 
 * @param k 
 */
void printKLargest(int arr[], int n, int k)
{

    //Using MinHeap
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);

    for(int i=k; i<n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        else
            continue;
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main()
{
    int arr[] = {5, 15, 10, 20, 8};
    // int arr[] = {8, 6, 4, 10, 9};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 2;
    // int k = 3;

    printKLargest(arr, n, k);

    return 0;
}