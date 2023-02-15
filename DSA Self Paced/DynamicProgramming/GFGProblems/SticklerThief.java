/**
 * @file SticklerThief.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Stickler Thief
MediumAccuracy: 37.98%Submissions: 138K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

Constraints:
1 ≤ n ≤ 104
1 ≤ a[i] ≤ 104
 * 
 * @version 0.1
 * @date 2023-02-15 03:28 PM
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//{ Driver Code Starts
import java.util.*;
// import java.io.*;

class SticklerThief {
	public static void main(String[] args) {

		// taking input using Scanner class
		Scanner sc = new Scanner(System.in);

		// taking count of testcases
		int t = sc.nextInt();
		while (t-- > 0) {

			// taking count of houses
			int n = sc.nextInt();
			int arr[] = new int[n];

			// inserting money present in
			// each house in the array
			for (int i = 0; i < n; ++i)
				arr[i] = sc.nextInt();

			// calling method FindMaxSum() of class solve
			System.out.println(new Solution().FindMaxSum(arr, n));
		}

		sc.close();
	}
}
// } Driver Code Ends

class Solution {
	// Function to find the maximum money the thief can get.
	public int FindMaxSum(int arr[], int n) {
		// Your code here
		if (n == 0)
			return 0;

		if (n == 1)
			return arr[0];

		int dp[] = new int[n];

		dp[0] = arr[0];
		dp[1] = Math.max(arr[0], arr[1]);

		for (int i = 2; i < n; i++)
			dp[i] = Math.max(dp[i - 1], Math.max(dp[i - 2] + arr[i], arr[i]));

		return dp[n - 1];
	}
}