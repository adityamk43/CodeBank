/**
 * @file EditDistance.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Edit Distance problem is a problem where we have to convert the given string s1 into another given string s2 with minimum operations of insertion, deletion and replacement.
 * 
 * Edit Distance Problem is important problem from Computer Science Perspective!
 * 
 * Edit Distance has many applications like correct mispelled words or suggesting spelling errors (if a user type spelling of a word wrong, we can use edit distance to find out the closest word that is there in dictionary) or if you want to create a search engine system or dictionary and if user has written some word we can hint them close or wrong words store at a edit distance close to 1, or 2 or so on.. and show those in "Did you mean" like Google does.
 * 
 * Edit Distance has also applications in Bioinformatics.
 * 
 * Edit distance can be called as a variation of LCS Problem.
 * 
 * 
 * 
 * @version 0.1
 * @date 2022-12-18 09:33 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief PLAIN RECURSION
 * 
 * TIME COMPLEXITY: O(2^n) if n>=m
 * AUXILIARY SPACE: O(n) if n>=m
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @param m 
 * @return int 
 */
// int editDistance(string s1, string s2, int n, int m)
// {
//     if (n==0)   return m;
//     if (m==0)   return n;

//     if (s1[n-1] == s2[m-1])
//         return editDistance(s1, s2, n-1, m-1);
    
//     else
//         return 1 + min(
//             editDistance(s1, s2, n, m-1), //insert operation
//             min(editDistance(s1, s2, n-1, m-1), //delete operation
//             editDistance(s1, s2, n-1, m-1)) //replace operation
//         );
// }


/**
 * @brief D.P. Solution using Tabulation
 * 
 * TIME COMPLEXITY: ⊝(m*n)
 * AUXILIARY SPACE: ⊝(m*n)
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @param m 
 * @return int 
 */
int editDistance(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];

    for (int i=0; i<=n; i++)
        dp[i][0] = i;
    for (int j=0; j<=m; j++)
        dp[0][j] = j;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }

    return dp[n][m];
}

int main()
{
    //EXAMPLE 1
    // string s1="CAT";
    // string s2="CUT";

    //EXAMPLE 2
    // string s1="GEEK";
    // string s2="GEEKS";
    
    //EXAMPLE 3
    string s1="SATURDAY";
    string s2="SUNDAY";

    cout << editDistance(s1, s2, s1.length(), s2.length()) << endl;

    return 0;
}