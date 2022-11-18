/**
 * @file MinHeap.cpp
 * @author ADITYA BHARDWAJ
 * @brief Min Heap Implementation
 * @version 0.1
 * @date 2022-11-18 03:57 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

class MinHeap
{
    private:
    int *arr;
    int size;
    int capacity;

    public:
    MinHeap(int capacity)
    {
        size = 0;
        this->capacity = capacity;
        arr = new int[capacity];
    }

    //LECTURE 2
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    int parent(int i) { return (i-1)/2; } /*floor of (i-1)/2, basically integer division*/


    //LECTURE 3
    void insert(int val);

    //LECTURE 4
    void minHeapify(int i);

    int extractMin();

    //Simple function by me just to check array elements and for debugging
    void printMinHeap()
    {
        for (int i=0; i<size; i++)
            cout << arr[i] << " ";
        
        cout << endl;
    }

    //NOTE: This function is only being implemented to check working of minHeapify. This function is not be means is related to MinHeap!!
    void setArray()
    {
        arr[0] = 40;
        arr[1] = 20;
        arr[3] = 35;
        arr[4] = 25;
    }

};


/**
 * @brief 
 * LECTURE 3
 * TIME COMPLEXITY OF INSERTION: log (size of this heap)
 * 
 */
void MinHeap::insert(int val)
{
    if (size == capacity)   return;

    size++;
    arr[size-1] = val;

    for (int i=(size-1); i>=0 && arr[parent(i)] > arr[i]; i=parent(i))
        swap(arr[parent(i)], arr[i]);
}

/**
 * @brief 
 * LECTURE 4
 * TIME COMPLEXITY: O(H) -> O(log n) where n is total no. of nodes in MinHeap
 * BEST CASE: ⊝(1)
 * WORST CASE: ⊝(H) -> ⊝(log n)
 * 
 * AUXILIARY SPACE: O(H) -> O(log n)
 * 
 * Here We are given node index i of an array i.e. Node that is to be fixed and not following MinHeap property -> the value of a node should be smaller than its descendant i.e. smaller than left and right child in Binary MinHeap!!
 * 
 * @param i 
 */
void MinHeap::minHeapify(int i)
{
    int leftChild = left(i);
    int rightChild = right(i);

    int smallest = i;

    if (leftChild < size && arr[leftChild] < arr[i])
        smallest = leftChild;
    if (leftChild < size && arr[rightChild] < arr[smallest])
        smallest = rightChild;
    
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }

}

/**
 * @brief 
 * THE ABOVE FUNCTION CAN ALSO BE IMPLEMENTED USING ITERATION INSTEAD OF RECURSION TO SAVE AUXILIARY SPACE
 * TIME COMPLEXITY: O(H) -> O(log n) where n is total no. of nodes in MinHeap
 * BEST CASE: ⊝(1)
 * WORST CASE: ⊝(H) -> ⊝(log n)
 * 
 * AUXILIARY SPACE: O(1)
 * @param i 
 */
// void MinHeap::minHeapify(int i)
// {
//     int leftChild = left(i);
//     int rightChild = right(i);

//     while (i<size)
//     {
//         int smallest = i;

//         if (leftChild < size && arr[leftChild] < arr[i])
//             smallest = leftChild;
//         if (leftChild < size && arr[rightChild] < arr[smallest])
//             smallest = rightChild;
        
//         if (smallest != i)
//             swap(arr[i], arr[smallest]);
//         else
//             break;
        
//         i=smallest;
//         leftChild = left(i);
//         rightChild = right(i);

//     }

// }

/**
 * @brief TIME COMPLEXITY: ⊝(1) + O(logn) (logn for MinHeapify Function)
 *        AUXILIARY SPACE: O(log n) for recursive implementation
 *                         O(1) for iterative implemenation
 * 
 * In MinHeap Minimum Value if always at 0th index or we can say root of the Binay MinHeap Tree
 * 
 * So, ExtractMin function extract and removes MIN Node from the Tree and apply MinHeapify to maintain MinHeap property on the Tree
 * 
 */
int MinHeap::extractMin()
{
    //if MinHeap is empty then return Max Value
    if (size == 0)
        return INT_MAX;

    //if there is only one node in MinHeap then simply return that value
    //this corner case if condition will prevent to call MinHeapify function for one element MinHeap as it will throw error for recursive implemenation of MinHeapify as it assumes that there will be values in MinHeap and therefore we don't want to get error
    if (size == 1)
    {
        size--;
        return arr[0];
    }

    //swapping min value with last element
    swap(arr[0], arr[size-1]);
    //reducing size of array by one since we are extracting min value
    size--;

    //calling minHeapify for arr[0] since, we swapped last element with min element and the MinHeap property is not being followed now
    minHeapify(0);

    //since, we reduced the arr size by 1 so, the last element will be at position size and not (size-1)
    return arr[size];
    
}



int main()
{
    MinHeap mh(50);

    //LECTURE 3
    // mh.insert(10);
    // mh.insert(20);
    // mh.insert(15);
    // mh.insert(40);
    // mh.insert(50);
    // mh.insert(100);
    // mh.insert(25);
    // mh.insert(45);

    // mh.printMinHeap();
    // mh.insert(12);
    // mh.printMinHeap();

    //LECTURE 4

    //MinHeapify Example
    // mh.insert(40);
    // mh.insert(20);
    // mh.insert(30);
    // mh.insert(35);
    // mh.insert(25);
    // mh.insert(80);
    // mh.insert(32);
    // mh.insert(100);
    // mh.insert(70);
    // mh.insert(60);
    
    // mh.setArray();
    // mh.minHeapify(0);
    // mh.printMinHeap();

    //Extract Min Example
    mh.insert(20);
    mh.insert(25);
    mh.insert(30);
    mh.insert(35);
    mh.insert(40);
    mh.insert(80);
    mh.insert(32);
    mh.insert(100);
    mh.insert(70);
    mh.insert(60);

    cout << mh.extractMin() << endl;
    mh.printMinHeap();

    return 0;
}