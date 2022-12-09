/**
 * @file LargestNumberWithGivenSum.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Largest number with given sum
EasyAccuracy: 44.25%Submissions: 40K+Points: 2
Geek lost the password of his super locker. He remembers the number of digits N as well as the sum S of all the digits of his password. He know that his password is the largest number of N digits that can be made with given sum S. As he is busy doing his homework, help him retrieving his password.

Example 1:

Input:
N = 5, S = 12
Output:
93000
Explanation:
Sum of elements is 12. Largest possible 
5 digit number is 93000 with sum 12.
Example 2:

Input:
N = 3, S = 29
Output:
-1
Explanation:
There is no such three digit number 
whose sum is 29.
Your Task : 
You don't need to read input or print anything. Your task is to complete the function largestNumber() which takes 2 integers N and S as input parameters and returns the password in the form of string, else return "-1" in the form of string.

Constraints:
1 ≤ N ≤ 104
0 ≤ S ≤ 9*104

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
 * 
 * @version 0.1
 * @date 2022-12-09 05:39
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
import java.io.*;
// import java.lang.*;
// import java.util.*;

class LargestNumberWithGivenSum {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // testcases
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");

            // taking n and sum
            int n = Integer.parseInt(inputLine[0]);
            int sum = Integer.parseInt(inputLine[1]);

            // calling largestNumber() function
            System.out.println(Solution.largestNumber(n, sum));
        }
    }
}
// } Driver Code Ends

class Solution {
    // Function to return the largest possible number of n digits
    // with sum equal to given sum.
    static String largestNumber(int n, int sum) {
        // add your code here
        if (n * 9 < sum)
            return "-1";

        String pass = "";
        int num = 9;

        while (n > 0) {
            if (num <= sum) {
                pass += Integer.toString(num);
                sum -= num;
                n--;
            } else
                num--;

        }

        return sum != 0 ? "-1" : pass;
    }
}
