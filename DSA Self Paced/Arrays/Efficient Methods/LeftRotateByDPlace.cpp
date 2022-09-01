/**
 * @file LeftRotateByDPlace.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 11:37PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>

using namespace std;

//BETTER SOLUTION

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊝(d)
*/

// void leftRotateByDPlace(vector<int> &arr, int d)
// {
//     int temp[d]; 
    
//     for (int i=0; i<d; i++)
//         temp[i] = arr[i];

//     for (int i=d; i<arr.size(); i++)
//         arr[i-d] = arr[i];

//     for (int i=0; i<d; i++)
//         arr[arr.size()-d+i] = temp[i];
// }

//EFFICIENT SOLUTION (REVERSAL ALGORITHM)

void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

}

void leftRotateByDPlace(vector<int> &arr, int d)
{
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, arr.size()-1);
    reverseArray(arr, 0, arr.size()-1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    leftRotateByDPlace(arr, 2);

    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}