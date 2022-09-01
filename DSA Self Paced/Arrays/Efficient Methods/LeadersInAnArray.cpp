/**
 * @file LeadersInAnArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-02 12:16AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(n)
*/

//prints leaders in right to left order
//will require reverseArray function and ⊝(n) Auxiliary Space to print it in left to right order
void leaders(int *arr, int n)
{
    int curr_leader = arr[n-1];
    cout << curr_leader << " ";

    for(int i=n-2; i>=0; i--)
        if (curr_leader < arr[i])
        {
            curr_leader = arr[i];
            cout << curr_leader << " ";
        }
}

//printing leaders in left to right with ⊝(n) Auxiliary Space
// void reverseArray(vector<int> &arr)
// {
//     int start = 0, end = arr.size()-1;

//     while (start < end)
//     {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }

// }

// void leaders(int *arr, int n)
// {
//     vector<int> leader;
//     int curr_leader = arr[n-1];
//     leader.push_back(curr_leader);

//     for(int i=n-2; i>=0; i--)
//         if (curr_leader < arr[i])
//         {
//             curr_leader = arr[i];
//             leader.push_back(curr_leader);
//         }
    
//     reverseArray(leader);

//     for (int i=0; i<leader.size(); i++)
//         cout << leader[i] << " ";
    
// }


int main()
{
    int arr[] = {7, 10, 4, 3, 10, 6, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    leaders(arr, n);

    return 0;
}