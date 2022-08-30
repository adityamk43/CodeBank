/**
 * @file DeletionOnArrays.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-30 11:43 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    I/P: arr[] = {3, 8, 12, 5, 6}
        x=12
    
    O/P: arr[] = {3, 8, 5, 6, _}
    
    I/P: arr[] = {3, 8, 12, 5, 6}
        x=6
    
    O/P: arr[] = {3, 8, 12, 5, _} 
*/

/*
    Time Complexity: ⊝(n)
*/

int deleteElement(int *arr, int n, int x)
{
    int i;

    for (i=0; i<n; i++)
        if (arr[i] == x)
            break;
    
    if (i==n)
        return n;
    
    for (int j = i; j<n-1; j++)
        arr[j] = arr[j+1];

    return n-1;
}

int main()
{
    int arr[] = {3, 8, 12, 5, 6};

    int n = sizeof(arr)/sizeof(arr[0]);

    // int size = deleteElement(arr, n, 12);
    int size = deleteElement(arr, n, 6);

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";

    return 0;
}