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

int secondLargestElement(vector<int> arr)
{
    int max = -1;
    int secondMax = -1;

    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
        
        else if (arr[i] != max)
        {
            if (secondMax == -1 || arr[i] > secondMax)
                secondMax = arr[i];
        }

    }

    return secondMax;
}

int main()
{
    // vector<int> arr = {1, 3, 54, 8, 10};
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << secondLargestElement(arr);

    return 0;
}