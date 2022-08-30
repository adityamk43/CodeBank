/**
 * @file InsertingOnArrays.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-30 11:19 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    NOTE: We cannot insert in a fixed sized array if it is already full!!
    We can only insert in an array if it has extra space for newly inserted array
*/

/*
    I/P: arr[] = {5, 10, 20, _, _}
        x=7
        pos=2
    
    O/P: arr[] = {5, 7, 10, 20, _}
    
    I/P: arr[] = {5, 7, 10, 20, _}
        x=3
        pos=2
    
    O/P: arr[] = {5, 3, 7, 10, 20, _} 
*/

/*
    Time Complexity: O(n)

    Worst Case time complexity will be when we have to insert in the beginning itself!!

    Insert at the end: O(1)
    Insert at the Beginning: ⊝(n)
*/

/*Dynamic Size Insertion to be noted in Notes Copy** */

int insert(int *arr, int n, int capacity, int pos, int x)
{
    if (n==capacity)
        return n;
    
    int index = pos-1;

    for (int i=n-1; i>=index; i--)
        arr[i+1] = arr[i];

    arr[index] = x;

    return n+1;
}

int main()
{
    int arr[5] = {5,10,20};

    int size = insert(arr, 3, 5, 2, 7);

    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}