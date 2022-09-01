/**
 * @file CheckArraySorted.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-29 10:07PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

bool checkArraySorted(vector<int> arr)
{
    
    for (int i = 1; i< arr.size(); i++)
        if (arr[i] < arr[i-1])
            return false;

    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // vector<int> arr = {1, 2, 5, 4};

    cout << checkArraySorted(arr);

    return 0;
}