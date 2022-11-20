/**
 * @file MedianofaStream.cpp
 * @author ADITYA BHARDWAJ
 * @brief We want to find out all the median between element(s) while traversing all elements in an array
 * @version 0.1
 * @date 2022-11-20 03:18 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief TIME COMPLEXITY: O(nlogn)
 * 
 * Advantage of this algorithm over other is that heap is cache friendly so it is faster than other same T.C. related algorithms!!
 * 
 * @param arr 
 * @param n 
 */
void medianOfAStream(int *arr, int n)
{
    //We will be storing first half of number before median in a MaxHeap and second Half of sorted numbers in a MinHeap
    //MaxHeap
    priority_queue<int> s;

    //MinHeap
    priority_queue<int, vector<int>, greater<int>> g;

    s.push(arr[0]);
    cout << arr[0] << " ";

    for (int i=1; i<n; i++)
    {
        if (s.size() > g.size())
        {
            if (s.top() > arr[i])
            {
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else
                g.push(arr[i]);
            

            double median = (s.top() + g.top())/2.0;

            cout << median << " ";
        }
        else
        {
            if (arr[i] <= s.top())
                s.push(arr[i]);
            else
            {
                g.push(arr[i]);
                s.push(g.top());
                g.pop();
            }
            
            cout << s.top() << " ";
        }
    }

    cout << endl;
}

int main()
{

    // int arr[] = {25, 7, 10, 15, 20};
    int arr[] = {12, 15, 10, 5, 8, 7, 16};

    int n = sizeof(arr)/sizeof(arr[0]);

    medianOfAStream(arr, n);

    return 0;
}