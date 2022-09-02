/**
 * @file StockBuyAndSell.java
 * @author ADITYA BHARDWAJ
 * @brief Stock buy and sell
MediumAccuracy: 39.53%Submissions: 90220Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

The cost of stock on each day is given in an array A[] of size N. Find all the segment of days on which you buy and sell the stock so that in between those days your profit is maximum.

Note: Since there can be multiple solutions, the driver code will return 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will return the string "No Profit" for a correct solution.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will
give us maximum profit. Now, we buy
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will
give us maximum profit.

Your Task:
The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs i.e. first value of pair will represent the day on which you buy the stock and second value represent the day on which you sell that stock. If there is No Profit, return an empty list.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
2 ≤ N ≤ 106
0 ≤ A[i] ≤ 106
 * @version 0.1
 * @date 2022-09-03 12:35AM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class StockBuyAndSell {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int A[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                A[i] = Integer.parseInt(inputLine[i]);
            }
            int p = 0;
            for (int i = 0; i < n - 1; i++)
                p += Math.max(0, A[i + 1] - A[i]);

            Solution obj = new Solution();
            ArrayList<ArrayList<Integer>> ans = obj.stockBuySell(A, n);
            if (ans.size() == 0)
                System.out.print("No Profit");
            else {
                int c = 0;
                for (int i = 0; i < ans.size(); i++)
                    c += A[ans.get(i).get(1)] - A[ans.get(i).get(0)];

                if (c == p)
                    System.out.print(1);
                else
                    System.out.print(0);
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find the days of buying and selling stock for max profit.
    ArrayList<ArrayList<Integer>> stockBuySell(int A[], int n) {
        // code here
        ArrayList<ArrayList<Integer>> stocksBuyAndSell = new ArrayList<>();

        if (n == 1)
            return stocksBuyAndSell;

        int i = 0;

        while (i < n - 1) {

            while (i < n - 1 && A[i + 1] <= A[i])
                i++;

            if (i == n - 1)
                return stocksBuyAndSell;

            ArrayList<Integer> stocks = new ArrayList<>();
            int buy = i++;
            stocks.add(buy);

            while (i < n && A[i] >= A[i - 1])
                i++;

            int sell = i - 1;
            stocks.add(sell);

            // stocksBuyAndSell.add({buy,sell});
            stocksBuyAndSell.add(stocks);

        }

        return stocksBuyAndSell;
    }
}
