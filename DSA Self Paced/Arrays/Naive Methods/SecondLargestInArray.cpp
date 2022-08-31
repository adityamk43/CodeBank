/**
 * @file SecondLargestInArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 01:51AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Please Note that this method is not that naive, this also takes linear case time complexity, it's just that it uses two traversals to find second largest element in an array.
 * In Efficient Method, we are doing this thing in just one traversal.
 * 
 * THAT IS THE ONLY DIFFERENCE BETWEEN Naive and Efficient Method!!!
 * 
 */
/*
    TIME COMPLEXITY: ⊖(n)
*/

#include <bits/stdc++.h>

using namespace std;

int getLargest(vector<int> arr)
{
    int res = 0;

    for (int i=1; i<arr.size(); i++)
        if (arr[i] > arr[res])
            res = i;

    return res;
}

int secondLargest(vector<int> arr)
{
    int largest = getLargest(arr);
    int res = -1;

    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i]!=arr[largest])
        {
            if (res == -1)
                res = i;
            else if (arr[i] > arr[res])
                res = i;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 5, 8, 20};
    // vector<int> arr = {10, 10, 10};

    int largest = getLargest(arr);
    int secondLargestIndex = secondLargest(arr);

    // cout << secondLargestIndex << endl;
    cout << "Largest: " << arr[largest] << endl;
    cout << "Second Largest: " << arr[secondLargestIndex];

    return 0;
}