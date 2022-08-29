/**
 * @file removeDuplicatesFromArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-29 10:16PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int res = 1;

    for (int i=1; i< arr.size(); i++)
    {
        if (arr[res-1] != arr[i])
        {
            arr[res] = arr[i];
            res++;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3};

    int res = removeDuplicates(arr);

    for (int i=0; i<res; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}