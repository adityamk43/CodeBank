/**
 * @file EqualSumPartition.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Equal Sum Partition
MediumAccuracy: 20.68%Submissions: 104K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Example 1:

Input:
N = 4
arr[] = {1,5,11,5}
Output: YES
Explanation: There exists two subsets
such that {1, 5, 5} and {11}.
Example 2:

Input:
N = 3
arr[] = {1,3,5}
Output: NO
Your Task:
Your task is to complete the findPartition() function which takes an array a[] and N as input parameter and return true if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else return false.
Note: The output will be YES or NO depending upon the value returned by your code. The printing is done by the driver's code.

Expected Time Complexity: O(N*S).
Expected Auxiliary Space: O(S) where S is the sum of the given Array.

Constraints:
1 <= N <= 100
0 <= arr[i] <= 1000
 * 
 * @version 0.1
 * @date 2023-02-15 11:07 PM
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 //{ Driver Code Starts
// Initial Template for Java

import java.io.*;
// import java.util.*;

class EqualSumPartition {
    public static void main(String[] args) throws IOException {
        
        //reading input using BufferedReader class
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
            
        //taking testcases
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {
            
            //reading size of array
            int n = Integer.parseInt(br.readLine().trim());

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            
            //inserting elements in the array
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            
            //creating an object of class Solution
            Solution ob = new Solution();
            
            //calling findPartition() method and
            //printing "YES", if it returns true
            //else "NO"
            if (ob.findPartition(a, n) == true) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution 
{
    //Recursive Approach
    // public boolean MyFP(int arr[], int n, int sum)
    // {
    //     if (sum==0)
    //         return true;
    //     if (n==0 && sum!=0)
    //         return false;
        
    //     if (sum < arr[n-1])
    //         return MyFP(arr, n-1, sum);
        
    //     return MyFP(arr, n-1, sum) || MyFP(arr, n-1, sum-arr[n-1]);
    // }
    
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    // public boolean findPartition(int[] a, int n)
    // {
    //     // code here
    //     int sum=a[0];
        
    //     for (int i=1; i<n; i++)
    //         sum+=a[i];
        
    //     if (sum%2!=0)
    //         return false;
        
    //     return MyFP(a, n, sum/2);
    // }
    
    
    //Dynamic Programming Tabulation Approach
    public boolean findPartition(int[] a, int n)
    {
        // code here
        int sum=a[0];
        
        for (int i=1; i<n; i++)
            sum+=a[i];
        
        if (sum%2!=0)
            return false;
        
        boolean dp[][] = new boolean[n+1][sum/2+1];
        
        for (int i=0; i<=n; i++)
            dp[i][0] = true;
        
        for (int j=1; j<=sum/2; j++)
            dp[0][j] = false;
        
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=sum/2; j++)
            {
                dp[i][j] = dp[i-1][j];
                
                if (j >= a[i-1])
                    dp[i][j] = dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
        
        return dp[n][sum/2];
    }
}