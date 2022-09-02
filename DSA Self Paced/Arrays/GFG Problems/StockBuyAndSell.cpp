/**
 * @file StockBuyAndSell.cpp
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
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> stocksBuyAndSell;
        // code here

        if (n == 1)
            return stocksBuyAndSell;

        int i = 0;

        while (i < n - 1)
        {

            while (i < n - 1 && A[i + 1] <= A[i])
                i++;

            if (i == n - 1)
                return stocksBuyAndSell;

            vector<int> stocks;
            
            int buy = i++;
            stocks.push_back(buy);

            while (i < n && A[i] >= A[i - 1])
                i++;

            int sell = i - 1;
            stocks.push_back(sell);

            // stocksBuyAndSell.push_back({buy, sell});
            stocksBuyAndSell.push_back(stocks);
            
        }

        return stocksBuyAndSell;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for (int i = 0; i < ans.size(); i++)
        c += A[ans[i][1]] - A[ans[i][0]];
    return (c == p) ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.stockBuySell(A, n);
        int p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i + 1] - A[i];
            if (x > 0)
                p += x;
        }
        if (ans.size() == 0)
            cout << "No Profit";
        else
        {
            cout << check(ans, A, p);
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends