/**
 * @file LargestElementInArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 01:19AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
    TIME COMPLEXITY: O(n^2)

    Best Case: When largest element is found at first index
                ⊖(n)
    Worst Case: When largest element is found at last index
                ⊖(n^2)
*/

#include <bits/stdc++.h>

using namespace std;

int getLargest(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        bool flag = true;

        for (int j=0; j<n; j++)
            if (arr[j] > arr[i])
                flag = false;
        
        if (flag == true)
            return arr[i];
    }

    //this line will never be reached. This line is written so the compiler doesn't give warnings about return statement
    return -1;
}

int main()
{
    int arr[] = {5, 8, 20, 10};

    cout << getLargest(arr, 4);

    return 0;
}