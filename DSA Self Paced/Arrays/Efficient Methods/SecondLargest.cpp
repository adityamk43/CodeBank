/**
 * @file SecondLargest.cpp
 * @author Aditya Bhardwaj
 * @version 0.1
 * @date 2022-08-29 09:58PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊖(n)
    AUXILIARY SPACE: ⊖(1)

    It finds the Second Largest in One Traversal Only
*/

/*
    DRY RUN: 
    {5, 20, 12, 20, 8}
    largest = 0, res = -1

    i=1: res = 0, largest = 1
    i=2: res = 2
    i=3: IGNORE
    i=4: IGNORE
*/
int secondLargest(vector<int> arr)
{
    int largest = 0;
    int res = -1;

    for (int i=1; i<arr.size(); i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
                res = i;
        }

    }

    return res;
}

int main()
{
    vector<int> arr = {20, 10, 20, 8, 12};
    // vector<int> arr = {10, 10, 10};

    int secondLargestIndex = secondLargest(arr);

    // cout << secondLargestIndex << endl;
    cout << "Second Largest: " << arr[secondLargestIndex];

    return 0;
}