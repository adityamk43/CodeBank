/**
 * @file BitonicSubsequence.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Longest Bitonic subsequence
MediumAccuracy: 47.34%Submissions: 43K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.


Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.


Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)


Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 106
 * 
 * @version 0.1
 * @date 2022-12-23 11:32 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class BitonicSubsequence {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine().trim();
            String[] s1 = s.split(" ");
            int[] nums = new int[n];
            for (int i = 0; i < s1.length; i++)
                nums[i] = Integer.parseInt(s1[i]);
            Solution ob = new Solution();
            int ans = ob.LongestBitonicSequence(nums);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    public int LongestBitonicSequence(int[] nums) {
        // Code here
        int n = nums.length;

        int lis[] = new int[n];
        int lds[] = new int[n];

        for (int i = 0; i < n; i++) {
            lis[i] = 1;
            lds[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    lis[i] = Math.max(lis[i], lis[j] + 1);
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i])
                    lds[i] = Math.max(lds[i], lds[j] + 1);
            }
        }

        int max_val = lis[0] + lds[0] - 1;

        for (int i = 1; i < n; i++)
            max_val = Math.max(max_val, lis[i] + lds[i] - 1);

        return max_val;

    }
}