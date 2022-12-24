/**
 * @file MinimumJumpsONSolution.java
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 *        Minimum number of jumps
 *        MediumAccuracy: 20.16%Submissions: 102K+Points: 4
 *        Lamp
 *        Land your Dream Job with Mega Job-a-thon. Register Now!
 * 
 *        Given an array of integers where each element represents the max
 *        number of steps that can be made forward from that element. The task
 *        is to find the minimum number of jumps to reach the end of the array
 *        (starting from the first element). If an element is 0, then cannot
 *        move through that element.
 * 
 *        Example 1:
 * 
 *        Input:
 *        N = 11
 *        a[] = {1,3,5,8,9,2,6,7,6,8,9}
 *        Output: 3
 *        Explanation: First jump from 1st element,
 *        and we jump to 2nd element with value 3.
 *        Now, from here we jump to 5h element with
 *        value 9. and from here we will jump to
 *        last.
 *        Example 2:
 * 
 *        Input:
 *        N = 6
 *        a[] = {1,4,3,2,6,7}
 *        Output: 2
 *        Your Task:
 *        Complete the function minimumJump() which takes an array and N (number
 *        of elements) as input parameters and returns the answer(if no answer
 *        possible return -1)
 * 
 *        Expected Time Complexity : O(N)
 *        Expected Auxiliary Space: O(N)
 * 
 *        Constraints:
 *        1 ≤ N ≤ 105
 *        0 <= ai <= 105
 * 
 * @version 0.1
 * @date 2022-12-24 04:27 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
import java.io.*;

class MinimumJumpsONSolution {
    public static void main(String[] args) throws IOException {

        // reading input using BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // reading total testcases
        int t = Integer.parseInt(br.readLine());

        int numOfTestCases = t;

        for (int p = 0; p < numOfTestCases; p++) {
            // reading size of array
            int size = Integer.parseInt(br.readLine());
            String[] arrStr = ((String) br.readLine()).split("\\s+");
            int[] arr = new int[size];

            // adding elements to the Array
            for (int i = 0; i < size; i++) {
                arr[i] = Integer.parseInt(arrStr[i]);
            }

            // creating an object of class DynamicProgramming
            // Solution obj = new Solution();

            // calling method minimumJumps() of class
            // DynamicProgramming
            System.out.println(Solution.minimumJumps(arr, size));
        }
    }

}

// } Driver Code Ends

class Solution {
    // Function to find minimum number of jumps to reach the end of the array.
    public static int minimumJumps(int arr[], int n) {
        // your code here
        if (n <= 1)
            return 0;

        if (arr[0] == 0)
            return -1;

        int maxReach = arr[0];
        int step = arr[0];
        int jump = 1;

        for (int i = 1; i < n; i++) {
            if (i == n - 1)
                return jump;

            maxReach = Math.max(maxReach, i + arr[i]);

            step--;

            if (step == 0) {
                jump++;

                if (i >= maxReach)
                    return -1;

                step = maxReach - i;
            }
        }

        return -1;
    }
}
