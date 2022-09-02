/**
 * @file CheckArraySortedAndRotated.cpp
 * @author ADITYA BHARDWAJ
 * @brief Check if array is sorted and rotated
MediumAccuracy: 38.92%Submissions: 30742Points: 4
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted
(1, 2, 3, 4) and rotated twice
(3, 4, 1, 2).
Example 2:

Input:
N = 3
arr[] = {1,2,3}
Output: No
Explanation: The array is sorted
(1, 2, 3) is not rotated.
Your Task:
The task is to complete the function checkRotatedAndSorted() which returns true if an array is sorted and rotated clockwise otherwise false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
1 <= A[i] <= 106
 * @version 0.1
 * @date 2022-09-02 02:37PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    // Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num)
    {

        // Your code here
        int x = 0, y = 0;

        for (int i = 0; i < num - 1; i++)
        {
            if (arr[i] < arr[i + 1])
                x++;
            else
                y++;
        }

        if (x == 1 || y == 1)
        {
            if (arr[num - 1] < arr[0])
                x++;
            else
                y++;

            if (x == 1 || y == 1)
                return true;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    // testcases
    cin >> T;

    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; ++i)
            cin >> arr[i];

        bool flag = false;
        Solution ob;

        // function call
        flag = ob.checkRotatedAndSorted(arr, num);

        // printing "No" if not sorted and
        // rotated else "Yes"
        if (!flag)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }

    return 0;
}
// } Driver Code Ends