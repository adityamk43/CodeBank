/**
 * @file BlackAndWhite.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Black and White
MediumAccuracy: 51.2%Submissions: 20K+Points: 4
Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

Note:
The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.

Example 1:

Input:
N = 2, M = 2
Output: 12
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

Example 2:

Input:
N = 2, M = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Your Task:
Your task is to complete the function numOfWays() which takes the chessboard dimensions N and M as inputs and returns the number of ways we can place 2 Knights on this chessboard such that they cannot attack each other. Since this number can be very large, return it modulo 109+7.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N * M <= 105

Alternative approach
Intuition
We can solve this problem more efficiently .  The arrangements in this case where knight to move 2 steps in the horizontal direction and 1 step in the vertical. where attack is possible are equal to 4 * (N – 2) * (M – 1) and similarly for 2 steps in the vertical direction and 1 step in the horizontal , where attack is possible are equal to 4* (N-1) * (M-2). Thus the answer will be Total possible arrangement – 4 * (N – 2) * (M – 1) – 4 * (N – 1) * (M – 2).

Implementation
check if N is greater then or equal to 2 and M is greater than or equal to 1. then substract 4 * (N – 2) * (M – 1) from all possible arrangements
check if M is greater than or equal to 1 and N is greater than or equal to 2 . then substract  4* (N-1) * (M-2) from all possible arrangements
complexity
Time complexity : time complexity is O(1)
Space complexity : O(1)

long long numOfWays(int N, int M)
{
    long long MOD = 1e9 + 7;

    long long nm = ((long long)N * (long long)M) % MOD;

    long long nm1 = ((nm - 1L + MOD) % MOD);

    long long ans = ( nm1 * nm) % MOD;

    if ((long long) N >= 1 && (long long)M >= 2) {
        // Attacks possible in one horizontal
        // and two vertical steps
        ans = ans - (4L * ((((long long)N - 1L + MOD) % MOD) * ((long long)M - 2L + MOD) % MOD) % MOD);
    }
    if ((long long)N >= 2 && (long long)M >= 1) {
        // Attacks possible in Two horizontal
        // and one vertical steps
        ans = ans - (4L * ((((long long)N - 2L + MOD) % MOD) * ((long long)M - 1L + MOD) % MOD) % MOD);
    }

    return ans;
}
 *
 * @version 0.1
 * @date 2022-12-12 03:44 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main()
{
    // code
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find out the number of ways we can place a black and a
// white Knight on this chessboard such that they cannot attack each other.
bool isSafe(int i, int j, int N, int M)
{
    return (i >= 1 && j >= 1 && i <= N && j <= M);
}

long long numOfWays(int N, int M)
{
    // write code here
    int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
    int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

    long long total_arrangements = N * M;

    long long mod = 1000000007;

    long long count = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (isSafe(i + dx[k], j + dy[k], N, M))
                    count++;
            }
        }
    }

    long long ans = total_arrangements * (total_arrangements - 1);

    return (ans - count) % mod;
}

// long long numOfWays(int N, int M)
// {
//     long long MOD = 1e9 + 7;

//     long long nm = ((long long)N * (long long)M) % MOD;

//     long long nm1 = ((nm - 1L + MOD) % MOD);

//     long long ans = ( nm1 * nm) % MOD;

//     if ((long long) N >= 1 && (long long)M >= 2) {
//         // Attacks possible in one horizontal
//         // and two vertical steps
//         ans = ans - (4L * ((((long long)N - 1L + MOD) % MOD) * ((long long)M - 2L + MOD) % MOD) % MOD);
//     }
//     if ((long long)N >= 2 && (long long)M >= 1) {
//         // Attacks possible in Two horizontal
//         // and one vertical steps
//         ans = ans - (4L * ((((long long)N - 2L + MOD) % MOD) * ((long long)M - 1L + MOD) % MOD) % MOD);
//     }

//     return ans;
// }