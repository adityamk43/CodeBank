/**
 * @file nCr.java
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 * nCr
MediumAccuracy: 22.67%Submissions: 17K+Points: 4
Lamp
Land your Dream Job with Mega Job-a-thon. Register Now!  

Find nCr for given n and r.

Example 1:

Input:
n = 3, r = 2
Output: 3
Example 2:

Input:
n = 4, r = 2
Output: 6
Your Task:
Complete the function nCrModp() which takes two integers n and r as input parameters and returns the nCr mod 109+7.
Note: nCr does not exist when r > n. Hence, return 0 in that case.

Expected Time Complexity : O(N*R)
Expected Auxiliary Space: O(N)

Constraints:
1<= n <= 10^3
1<= r <= 10^3
 * 
 * @version 0.1
 * @date 2022-12-27 05:57 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//05:57 pm
//{ Driver Code Starts
// import java.lang.*;
// import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) {
        // taking input using Scanner class
        Scanner s = new Scanner(System.in);

        // taking total count of testcases
        int testcase = s.nextInt();
        while (testcase > 0) {

            int n = s.nextInt(); // Input n
            int r = s.nextInt(); // Input p

            // creating an object of class DynamicProgramming
            // Solution obj = new Solution();

            // calling method nCrModp() of class
            // DynamicProgramming
            System.out.println(Solution.nCrModp(n, r));

            testcase--;
        }

        s.close();
    }

}

// } Driver Code Ends

class Solution {
    // Function to return nCr mod 10^9+7 for given n and r.
    // RECURSION WITH OVERLAPPINGS
    // public static int nCrModp(int n, int r)
    // {
    // // your code here
    // if (r>n)
    // return 0;

    // if (r==n || r==0)
    // return 1;

    // int mod=1000000007;

    // return (nCrModp(n-1, r-1)%mod + nCrModp(n-1, r)%mod)%mod;

    // }

    public static int nCrModp(int n, int r) {
        if (r > n)
            return 0;

        if (r == n || r == 0)
            return 1;

        int dp[] = new int[r + 1];

        dp[0] = 1;

        int mod = 1000000007;

        for (int i = 1; i <= n; i++)
            for (int j = Math.min(i, r); j >= 1; j--)
                dp[j] = (dp[j - 1] % mod + dp[j] % mod) % mod;

        return dp[r];
    }
}
