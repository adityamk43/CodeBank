/**
 * @file reverseArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-29 10:12PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseArray(int *arr, int n)
{
    int start = 0, end = n-1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    reverseArray(arr, 5);

    for (int i=0; i<5; i++)
        cout << arr[i] << " ";
    return 0;
}