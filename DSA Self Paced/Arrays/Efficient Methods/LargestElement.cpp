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

int largestElement(vector<int> arr)
{
    int max = -1;
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    vector<int> arr = {1, 3, 54, 8, 10};

    cout << largestElement(arr);

    return 0;
}