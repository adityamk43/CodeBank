/**
 * @file WriteNwaystoWriteSum.java
 * @author ADITYA BHARDWAJ
 * @brief
 *
Ways to write n as sum
EasyAccuracy: 34.53%Submissions: 14K+Points: 2
Lamp
Land your Dream Job with Mega Job-a-thon. Register Now!  

Given a positive integer N, the task is to find the number of different ways in which N can be written as a sum of two or more positive integers.

Example 1:

Input:
N = 5
Output: 6
Explanation: 
1+1+1+1+1
1+1+1+2
1+1+3
1+4
2+1+2
2+3
So, a total of 6 ways.
Example 2:

Input:
N = 3
Output: 2
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 103
 *
 * @version 0.1
 * @date 2022-12-22 02:19 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
import java.util.*;

//PLAIN RECURSION TECHNIQUE WITH OVERLAPPINGS
//TIME COMPLEXITY: O(2^n)
//AUXILIARY SPACE: O(n^2)
/** 
 * void printVector(vector<int>& arr)
 {
     if (arr.size() != 1) {
         
        // Traverse the vector arr
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Recursive function to print different
// ways in which N can be written as
// a sum of at 2 or more positive integers
//starts with i=1 
void findWays(vector<int>& arr, int i, int n)
{
    // If n is zero then print this
    // ways of breaking numbers
    if (n == 0)
        printVector(arr);
 
    // Start from previous element
    // in the representation till n
    for (int j = i; j <= n; j++) {
 
        // Include current element
        // from representation
        arr.push_back(j);
 
        // Call function again
        // with reduced sum
        findWays(arr, j, n - j);
 
        // Backtrack to remove current
        // element from representation
        arr.pop_back();
    }
}
 */

class WriteNwaystoWriteSum {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- > 0) {
            int n = s.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.countWays(n));
        }

        s.close();
    }
}

// } Driver Code Ends

class Solution {
    // function to count ways in which n can be
    // expressed as the sum of two or more integers
    int countWays(int n) {

        // your code here
        int dp[] = new int[n + 1];

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i] % 1000000007;
            }
        }

        return dp[n];
    }
}
