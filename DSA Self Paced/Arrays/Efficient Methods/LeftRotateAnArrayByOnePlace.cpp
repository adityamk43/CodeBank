/**
 * @file LeftRotateAnArrayByOnePlace.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 09:23PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void leftRotateByOnePlace(vector<int> &arr)
{
    int temp = arr[0];

    for (int i=0; i<arr.size()-1; i++)
    {
        arr[i] = arr[i+1];
    }

    arr[arr.size()-1] = temp;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr = {30, 5, 20};

    leftRotateByOnePlace(arr);

    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}