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

    //LECTURE 5
    void decreaseKey(int i, int x);

    void deleteKey(int i);

    void buildHeap();

    //NOTE: This function is only being implemented to check working of BUILD HEAP. This function is not by any means is related to MinHeap Implementation and operations!!
    void setArrayForBuildHeap()
    {
        //EXAMPLE 1
        size = 7;
        arr[0] = 10;
        arr[1] = 5;
        arr[2] = 20;
        arr[3] = 2;
        arr[4] = 4;
        arr[5] = 8;
        arr[6] = 25;

        //EXAMPLE 2
        // size = 3;
        // arr[0] = 30;
        // arr[1] = 20;
        // arr[2] = 10;
    }

    //Simple function by me just to check array elements and for debugging
    void printMinHeap()
    {
        for (int i=0; i<size; i++)
            cout << arr[i] << " ";
        
        cout << endl;
    }

    //NOTE: This function is only being implemented to check working of minHeapify. This function is not by any means is related to MinHeap Implementation and operations!!
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
//
//     while (i<size)
//     {
//         int smallest = i;
//
//         if (leftChild < size && arr[leftChild] < arr[i])
//             smallest = leftChild;
//         if (leftChild < size && arr[rightChild] < arr[smallest])
//             smallest = rightChild;
//
//         if (smallest != i)
//             swap(arr[i], arr[smallest]);
//         else
//             break;
//
//         i=smallest;
//         leftChild = left(i);
//         rightChild = right(i);
//
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

/**
 * @brief LECTURE 5
 * 
 *  TIME COMPLEXITY: O(logn)
 *  AUXILIARY SPACE: O(logn)
 * 
 * DECREASE KEY IS USED TO REPLACE THE VALUE OF THE GIVEN INDEX i WITH THE GIVEN VALUE x
 * 
 * @param i 
 * @param x 
 */
void MinHeap::decreaseKey(int i, int x)
{

    arr[i] = x;

    while (i!=0 && arr[parent(i)] > arr[i])
    {
        swap(arr[i], arr[parent(i)]);

        i = parent(i);
    }

}


/**
 * @brief LECTURE 5
 * 
 *        TIME COMPLEXITY: O(logn) (Decrease Key) + O(logn) (Extract Min)
 *                          O(logn)
 *        AUXILIARY SPACE: O(logn)
 * 
 * We do decrease key to replace the given Index value to be delted with -infinity Value (INT_MIN in cpp)
 * which will automatically heapify itself to root when extract min is called and that index value will be deleted
 * 
 * @param i 
 */
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

/**
 * @brief LECTURE 5
 * 
 *        TIME COMPLEXITY: O(n) [n=size] [This is derived using G.P. series derivation. Please look GFG MinHeap Build Heap implemenation lecture problem to understand time complexity derivation]
 * 
 * MY explanation for T.C. Derivation:
 * 
 * Max. no. of nodes at a height h = Ceil( n/2^(h+1) )
 * 
 * Thus, Total Time = upper Bound:logn (£) lower bound:h=1 ceil( n/2^(h+1) ) * O(h)
 *                  = O(n * upper Bound:logn (£) lower bound:h=1  h /2^(h+1) )
 * 
 * S = infinite (£) h=1 h /2^(h+1) = 1/2^2 + 2/2^3 + 3/2^4 + 4/2^5 + ....
 * S/2 =                                     1/2^3 + 2/2^4 + 3/2^5 + 4/2^6 + ....
 * 
 * (S-S/2) = 1/2^2 + 1/2^3 + 1/2^4 + .....
 * (The above equation is in Geometric Progression Therefore,)
 * 
 * Using Infinite Sum of G.P. Formula
 * S/2 = (1/2^2)/(1-1/2) = 1/2
 * 
 * 
 * S=1!!!!
 * 
 * This derivation is for h=1 to infinite but we are finding for h=1 to logn. So, it is not worrying as we are finding Big O here and it can be considered.
 * 
 * Therefore, in
 *          O(n * upper Bound:logn (£) lower bound:h=1  h /2^(h+1) )
 * Formula
 * 
 * We can consider {upper Bound:logn (£) lower bound:h=1  h /2^(h+1)} as 1
 * 
 * and the Total Time Complexity Becomes O(n)
 * 
 * Hence Proved!!!!
 * 
 * 
 * WE ARE GIVEN AN ARRAY AND WE WANT TO HEAPIFY AND REARRANGE THE GIVEN ARRAY INTO MIN HEAP ARRAY
 * 
 */
void MinHeap::buildHeap()
{
    //We will start with the bottom and right most internal node!!
    // since for last element parent is (size-1)-1/2 where i = size-1.

    for (int i = (size-2)/2; i>=0; i--)
        minHeapify(i);
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
    // mh.insert(20);
    // mh.insert(25);
    // mh.insert(30);
    // mh.insert(35);
    // mh.insert(40);
    // mh.insert(80);
    // mh.insert(32);
    // mh.insert(100);
    // mh.insert(70);
    // mh.insert(60);
    // cout << mh.extractMin() << endl;
    // mh.printMinHeap();

    //LECTURE 5
    // mh.insert(10);
    // mh.insert(20);
    // mh.insert(30);
    // mh.insert(40);
    // mh.insert(50);
    // mh.insert(35);
    // mh.insert(38);
    // mh.insert(45);

    // mh.printMinHeap();
    //Decrease Key Example
    // mh.decreaseKey(3, 15);

    //Delete Example
    // mh.deleteKey(3);

    // mh.printMinHeap();

    //LECTURE 5 - PART 3
    //Build Heap Example

    mh.setArrayForBuildHeap();
    mh.printMinHeap();
    mh.buildHeap();
    mh.printMinHeap();

    return 0;
}