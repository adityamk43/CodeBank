/**
 * @file LCSTabulation.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 *          Longest Common Subsequence (LCS) means we have to find the common subsequence in given two strings. Subsequences is different from substrings in a sense that substrings are continguous strings in given big string and subsequence is not continguous but it should be according to order the characters are present in strings.
 * 
 * Example: "ABCD"
 * 
 * "BCD" -> substring
 * "ACD" -> subsequence  
 * 
 * @version 0.1
 * @date 2022-12-18 02:02 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;


/**
 * @brief Since, here two parameters are changing i.e., m and n so, we will create an 2-D array of size m*n
 * 
 * USING TABULATION D.P. TECHNIQUE
 * 
 * TIME COMPLEXITY: ⊝(m*n)
 * AUXILIARY SPACE: ⊝(m*n)
 *  
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @param m 
 * @return int 
 */
int LCS(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];

    for (int i=0; i<=n; i++)
        dp[i][0] = 0;

    for (int j=0; j<=m; j++)
        dp[0][j] = 0;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
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