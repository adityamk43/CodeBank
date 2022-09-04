/**
 * @file MajorityElement.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-04 12:47 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n)
*/

/*
    MOORE'S VOTING ALGORITHM
*/

int findMajority(int arr[], int n)
{
    //First Phase
    //find a Candidate
    int count = 1;
    int res = 0;

    for (int i=1; i<n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else   
            count--;

        if (count == 0)
            res = i, count = 1;
    }


    //Second Phase
    //check if the candidate is actually the majority
    count = 0;
    for (int i=0; i<n; i++)
        if (arr[res] == arr[i])
            count++;

    if (count <= n/2)
        return -1;
    
    return res;

}

int main()
{
    // int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};
    // int arr[] = {3, 7, 4, 7, 7, 5};
    int arr[] = {8, 8, 6, 6, 6, 4, 6};
    // int arr[] = {6, 8, 4, 8, 8};

    int n =sizeof(arr)/sizeof(arr[0]);

    int index = findMajority(arr, n);

    cout << "Index: " << index << endl;
    
    if (index >= 0)
        cout << "Element: " << arr[index] << endl;


    return 0;
}