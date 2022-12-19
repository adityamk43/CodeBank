/**
 * @file LongestCommonSubsequence.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 *       Longest Common Subsequence (LCS) means we have to find the common subsequence in given two strings. Subsequences is different from substrings in a sense that substrings are continguous strings in given big string and subsequence is not continguous but it should be according to order the characters are present in strings.
 * 
 * Example: "ABCD"
 * 
 * "BCD" -> substring
 * "ACD" -> subsequence  
 * 
 * @version 0.1
 * @date 2022-12-18 01:35 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief PLAIN RECURSION SOLUTION
 * 
 * TIME COMPLEXITY: ⊝(2^n) where n>m
 * AUXILIARY SPACE: ⊝(n) where n>m
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @param m 
 * @return int 
 */
// int LCS(string s1, string s2, int n, int m)
// {
//     if (n==0 || m==0)
//         return 0;
    
//     if (s1[n-1] == s2[m-1])
//         return 1+LCS(s1, s2, n-1, m-1);
    
//     else
//         return max(LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1));
// }


/**
 * @brief USING MEMOIZATION D.P.
 * 
 * TIME COMPLEXITY: ⊝(m*n)
 * AUXILIARY SPACE: ⊝(m*n)
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @param m 
 * @param memo 
 * @return int 
 */
int LCSMemo(string s1, string s2, int n, int m, vector<vector<int>> &memo)
{
    if (memo[n][m] != -1)
        return memo[n][m];
    
    if (n==0 || m==0)
        memo[n][m] = 0;
    
    else
    {
        if (s1[n-1] == s2[m-1])
            memo[n][m] = 1 + LCSMemo(s1, s2, n-1, m-1, memo);
        else
            memo[n][m] = max(LCSMemo(s1, s2, n-1, m, memo), LCSMemo(s1, s2, n, m-1, memo));
    }

    return memo[n][m];
}

/**
 * @brief Since, here two parameters are changing i.e., m and n so, we will create an 2-D array of size m*n
 * 
 */
int LCS(string s1, string s2, int n, int m)
{
    vector<vector<int>> memo(n+1, vector<int> (m+1, -1));

    return LCSMemo(s1, s2, n, m, memo);
}

int main()
{
    //EXAMPLE 1
    // string s1 = "ABCDGH";
    // string s2 = "AEDFHR";

    //EXAMPLE 2
    // string s1 = "AGGTAB";
    // string s2 = "GXTXAYB";

    //EXAMPLE 3
    // string s1 = "XYZ";
    // string s2 = "XYZ";
    
    //EXAMPLE 4
    string s1="AXYZ";
    string s2="BAZ";

    //EXAMPLE 5
    // string s1 = "ABC";
    // string s2 = "XY";

    cout << LCS(s1, s2, s1.length(), s2.length());

    return 0;
}