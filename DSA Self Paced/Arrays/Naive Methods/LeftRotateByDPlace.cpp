/**
 * @file LeftRotateByDPlace.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 10:53PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(nd)
    AUXILIARY SPACE: ⊝(1)
*/

/*
    We call the previous Left Rotate Array By One function d times to rotate the given array by d places
*/

void leftRotateByOnePlace(vector<int> &arr)
{
    int temp = arr[0];

    for (int i=1; i<arr.size(); i++)
        arr[i-1] = arr[i];

    arr[arr.size()-1] = temp;
}

void leftRotateByDPlace(vector<int> &arr, int d)
{
    for (int i=0; i<d; i++)
        leftRotateByOnePlace(arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> arr = {30, 5, 20};

    leftRotateByDPlace(arr, 2);

    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}