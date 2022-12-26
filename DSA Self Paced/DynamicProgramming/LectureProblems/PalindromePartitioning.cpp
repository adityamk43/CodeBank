/**
 * @file PalindromePartitioning.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given a string, we need to find minimum cuts we can make in this string to make all the substrings palindrome.
 * 
 * We will use the same idea of matrix chain multiplication problem to find palindrom partitioning. (We can also call this question as variation of Matrix Chain Multiplication).
 * 
 * s[0] s[1] s[2] ....... s[n-2] s[n-1]
 * 
 * (s[0]) (s[1] s[2] ....... s[n-2] s[n-1])
 * (s[0] s[1]) (s[2]...... s[n-2]s[n-1])
 * .
 * .
 * .
 * (s[0] s[1] s[2]....... s[n-2]) (s[n-1])
 *                                 First partitioning
 * 
 * BASE CASE: If whole string is palindrome return 0
 * 
 * Eg: geeks
 * (g) (eeks)
 * (ge) (eks)
 * (gee) (ks)
 * (geek) (s)
 * 
 * @version 0.1
 * @date 2022-12-26 08:57 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 
 * 
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isPalindrome(string &str, int i, int j)
{
    int start = i;
    int end = j;

    while(start<end)
    {
        if (str[start]!=str[end])
            return false;

        start++;
        end--;
    }

    return true;
}

/**
 * @brief PLAIN RECURSION WITH OVERLAPPINGS
 * 
 * TIME COMPLEXITY: EXPONENTIAL
 * 
 * @param s 
 * @param i 
 * @param j 
 * @return int 
 */
// int palPart(string s, int i, int j)
// {
//     if (isPalindrome(s, i, j))
//         return 0;
    
//     int res=INT_MAX;

//     for (int k=i; k<j; k++)
//         res = min(res, 1+palPart(s, i, k)+palPart(s, k+1, j));
    
//     return res;
// }

// int palPartSol(string s)
// {
    // return palPart(s, 0, s.length()-1);
// }

/**
 * @brief D.P. TABULATION TECHNIQUE
 * 
 * TIME COMPLEXITY: O(n^3)
 * AUXILIARY SPACE: ⊝(n^2)
 * 
 * As we did in Matrix Chain Multiplication, we will make dp[n][n] 2-D array and we will get answer in dp[0][n-1] and i<=j here, so array with dp[i][j] will not be filled where i>j
 * 
 * Here we have also optimised isPalindrome using D.P. in a sense that we will store isPalindrome data in an array table which will reduce isPalindrome function from O(n) to constant!
 * 
 * @param s 
 * @param i 
 * @param j 
 * @return int 
 */
int palPartSol(string s)
{
    int n=s.length();
    int dp[n][n];
    bool isPalindrome[n][n];

    for (int i=0; i<n; i++)
    {
        dp[i][i] = 0;
        isPalindrome[i][i] = true;
    }

    //gap variable is to maintain gap between i and j to fill in upper top-down diagonal direction
    for (int gap=1; gap<n; gap++)
    {
        for (int i=0; i+gap<n; i++)
        {
            int j=i+gap;

            if (s[i]==s[j] && (isPalindrome[i+1][j-1] || gap==1))
            {
                dp[i][j]=0;
                isPalindrome[i][j]=true;
            }
            else
            {
                isPalindrome[i][j]=false;
                dp[i][j]=INT_MAX;

                for (int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
            }

        }
    }

    return dp[0][n-1];
}

int main()
{
    //EXAMPLE 1
    string str1 = "geek"; //2
    cout << str1 << ": " << palPartSol(str1) << endl;

    //EXAMPLE 2
    string str2 = "abbac"; //1
    cout << str2 << ": " << palPartSol(str2) << endl;
    
    //EXAMPLE 3
    string str3 = "abcde"; //4
    cout << str3 << ": " << palPartSol(str3) << endl;
    
    //EXAMPLE 4
    string str4 = "aaaa"; //0
    cout << str4 << ": " << palPartSol(str4) << endl;
    
    //EXAMPLE 5
    string str5 = "abbabbc"; //2
    cout << str5 << ": " << palPartSol(str5) << endl;


    
    return 0;
}