/**
 * @file FindDuplicatesinArray.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Find duplicates in an array
Easy Accuracy: 20.69% Submissions: 100k+ Points: 2
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3
Explanation: 2 and 3 occur more than once
in the given array.
Your Task:
Complete the function duplicates() which takes array a[] and n as input as parameters and returns a list of elements that occur more than once in the given array in sorted manner. If no such element is found, return list containing [-1].

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array.

Constraints:
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i

 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /* HINT 1: Try to use the given array as a hash table.*/
    /*
    HINT 2: 1- Traverse the given array from i= 0 to n-1 elements
                Go to index arr[i]%n and increment its value by n.
            2- Now traverse the array again and print all those 
                indexes i for which arr[i]/n is greater than 1.

            This approach works because all elements are in range
            from 0 to n-1 and arr[i]/n would be greater than 1
            only if a value "i" has appeared more than once.
    */

    /* MY APPROACH THROUGH 2ND HINT AS I DON'T KNOW HASH WORKING TILL NOW BUT WILL TRY TO IMPLEMENT IT THROUGH AS LATER */
    vector<int> duplicates(int arr[], int n)
    {
        // code here
        vector<int> dup;

        for (int i = 0; i < n; i++)
        {
            // cout << "i " << i << " arr[" << i << "]: " << arr[i] << endl;
            // cout << "arr[i] % n " << arr[i] % n << endl;
            // cout << arr[arr[i] % n] << endl;    
            arr[arr[i] % n] += n;

            // cout << "Updated: " << arr[arr[i] % n] << endl;

        }

        for (int j = 0; j < n; j++)
        {   
            // cout << "arr[" << j << "] /" << n << ": " << arr[j] / n << endl;
            if ((arr[j] / n) > 1)
                dup.push_back(j);
        }

        if (dup.empty())
            dup.push_back(-1);

        return dup;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends