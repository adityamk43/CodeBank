/**
 * @file CountNthStairsOrderNotMatter.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Count ways to N'th Stair(Order does not matter)
MediumAccuracy: 62.68%Submissions: 32K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Example 1:

Input:
N = 4
Output: 3
Explanation: You can reach 4th stair in
3 ways.
3 possible ways are:
1, 1, 1, 1
1, 1, 2
2, 2
Example 2:

Input:
N = 5
Output: 3
Explanation:
You may reach the 5th stair in 3 ways.
The 3 possible ways are:
1, 1, 1, 1, 1
1, 1, 1, 2
1, 2, 2
Your Task:
Your task is to complete the function countWays() which takes single argument(N) and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 106
 * 
 * @version 0.1
 * @date 2023-02-14 11:52 AM
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.

    //MATHEMATICAL FORMULA FOUND USING OBSERVATION OF ANSWER
    long long countWays(int m)
    {
        // your code here
        return m/2+1;
    }

    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    //DP BASED SOLUTION
    // long long countWays(int m)
    // {
    //     long long res[m + 1];
        
    //     //base cases
    //     res[0] = 1;
    //     res[1] = 1;
        
    //     //storing number of ways to reach the ith index as 
    //     //number of ways to reach (i-2)th index +1.
    //     for (int i = 2; i <= m; i++)  
    //         res[i] = (res[i-2] + 1);
        
    //     //returning the result.
    //     return res[m];

    // }
};

//{ Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends