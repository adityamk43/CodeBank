/**
 * @file HeapSort.cpp
 * @author ADITYA BHARDWAJ
 * @brief Heap Sort is advanced and optimised version of Selection Sort. It uses MaxHeap for sorting
 * @version 0.1
 * @date 2022-11-19 04:05 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

void maxHeapify(int *arr, int n, int i)
{
    int left = 2*i + 1;
    int right = 2*i + 2;

    int largest = i;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i=(n-2)/2; i>=0; i--)
        maxHeapify(arr, n, i);
    
}

//My Code for HeapSort but not optimised!!
// void heapSort(int *arr, int n)
// {
//     buildHeap(arr, n);

//     swap(arr[0], arr[n-1]);

//     for (int i=(n-2); i>0; i--)
//     {
//         buildHeap(arr, i);
//         swap(arr[i], arr[0]);
//     }
// }

//Optimised Code
/**
 * @brief The Main Logic behind Heap Sort is:
 * 
 * 1.) We first Build a Max Heap from the given Array using Build Heap
 * 2.) Repeatedly swap root (Max element) with last node (Sim like Selection Sort), reduce heap size by one and do heapify.
 * 
 * SO, HEAP SORT CAN BE MAINLY SEEN AS AN IMPROVEMENT OF SELECTION SORT, IT USES HEAP DATA STRUCTURE AND THE CONCEPT OF SELECTION SORT.
 * 
 * SELECTION SORT => WORST CASE TIME COMPLEXITY: O(n^2)
 * HEAP SORT => TIME COMPLEXITY: O(nlogn), which is the best possible time we can get in any comparison based sorting algorithm.
 * 
 * OTHER SORT WHICH TAKES O(nlogn) TIME ARE MERGE SORT AND QUICK SORT
 * 
 * MERGE SORT => WORST CASE TIME COMPLEXITY: O(nlogn)
 * QUICK SORT => AVERAGE CASE TIME COMPLEXITY: O(nlogn)
 * HEAP SORT => IN ALL CASES TIME COMPLEXITY: O(nlogn)
 * 
 * 
 * When we compare heap sort with merge sort and quick sort, the constants hidden in heap sort are higher than merge sort and quick sort.
 * 
 * So, in practice merge sort and quick sort takes less time compared to heap sort and that is why merge sort and quick sort are used more in practice.
 * 
 * 
 * However there are hybrid algorithms like intro sort (standard algorithm in c++ stl), which uses hybrid of heap sort and quick sort. What happens in quick sort is it may go beyond O(nlogn) in certain cases, its recursion depth can become O(logn) and this intro sort algorithm switches to heap sort when the recursion depth goes beyond logn.
 * 
 * So, Heap Sort is not used as standard or main sorting algorithm in libraries but it is used as a helper sorting algorithm in hybrid algorithms.
 * 
 * @param arr 
 * @param n 
 */

void heapSort(int *arr, int n)
{
    //T.C. => O(n)
    buildHeap(arr, n);

    //T.C. => O(nlogn)
    for (int i=(n-1); i>0; i--)
    {
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
    }
}


void printArray(int *arr, int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

}

int main()
{
    int arr[] = {10, 15, 50, 4, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}