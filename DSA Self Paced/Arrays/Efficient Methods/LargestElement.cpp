/**
 * @file LargestElement.cpp
 * @author Aditya Bhardwaj
 * @version 0.1
 * @date 2022-08-29 09:54PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊖(n)
*/
int getLargest(vector<int> arr)
{
    int res = 0;

    for (int i=1; i<arr.size(); i++)
        if (arr[i] > arr[res])
            res = i;

    return res;
}

int main()
{
    vector<int> arr = {1, 3, 54, 8, 10};

    int largest = getLargest(arr);

    // cout << largest << endl;
    cout << arr[largest];

    return 0;
}