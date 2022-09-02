/**
 * @file RearrangeArray.java
 * @author ADITYA BHARDWAJ
 * @brief Rearrange an array with O(1) extra space
MediumAccuracy: 54.65%Submissions: 51399Points: 4
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].



Example 1:

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation:
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.


Example 2:

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation:
arr[arr[0]] = arr[4] = 3.
arr[arr[1]] = arr[0] = 4.
and so on.


Your Task:
You don't need to read input or print anything. The task is to complete the function arrange() which takes arr and N as input parameters and rearranges the elements in the array in-place.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)



Constraints:
1 <= N <= 107
0 <= Arr[i] < N
 * @version 0.1
 * @date 2022-09-02 05:03PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
// import java.lang.*;
// import java.util.*;

class RearrangeArray {

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        // testcases
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            // size of array
            int n = Integer.parseInt(read.readLine());
            String st[] = read.readLine().trim().split("\\s+");
            long arr[] = new long[(int) n];

            // adding elements to the array
            for (int i = 0; i < n; i++)
                arr[(int) i] = Integer.parseInt(st[(int) i]);

            // calling arrange() function
            new Solution().arrange(arr, n);

            // printing the elements
            for (int i = 0; i < n; i++)
                System.out.print(arr[i] + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {

    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    // with O(1) extra space.
    /*static*/ void arrange(long arr[], int n) {
        // your code here
        for (int i = 0; i < n; i++) {
            arr[i] %= n;

            arr[i] = n * (arr[(int) arr[i]] % n) + arr[i];
        }

        for (int i = 0; i < n; i++)
            arr[i] /= n;
    }
}
