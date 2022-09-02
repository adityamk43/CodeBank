/**
 * @file RotateArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief Rotate Array
EasyAccuracy: 50.28%Submissions: 100k+Points: 2
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.



Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
Example 2:

Input:
N = 10, D = 3
arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20
when rotated by 3 elements, it becomes
8 10 12 14 16 18 20 2 4 6.


Your Task:
Complete the function rotateArr() which takes the array, D and N as input parameters and rotates the array by D elements. The array must be modified in-place without using extra space.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)



Constraints:
1 <= N <= 106
1 <= D <= 106
0 <= arr[i] <= 105
 * @version 0.1
 * @date 2022-09-02
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
    // Function to rotate an array by d elements in counter-clockwise direction.
    void reverseArray(int arr[], int start, int end)
    {

        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotateArr(int arr[], int d, int n)
    {
        // code here
        d = d % n;
        reverseArray(arr, 0, d - 1);
        reverseArray(arr, d, n - 1);
        reverseArray(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        // input n and d
        cin >> n >> d;

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends