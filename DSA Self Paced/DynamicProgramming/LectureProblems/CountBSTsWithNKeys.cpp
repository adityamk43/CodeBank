/**
 * @file CountBSTsWithNKeys.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * 
 * 
 * @version 0.1
 * @date 2022-12-24 09:52 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursive Solution
 * 
 * Time Complexity: Exponential
 * 
 * @param n 
 * @return int 
 */
// int countBSTs(int n)
// {
//     if (n==0 || n==1)
//         return 1;
    
//     int res=0;
//     for (int i=1; i<=n; i++)
//         res+=countBSTs(i-1)*countBSTs(n-i);
    
//     return res;
// }

int countBSTs(int n)
{
    int dp[n+1];

    dp[0] = dp[1] = 1;

    for (int i=2; i<=n; i++)
    {
        dp[i]=0;

        for (int j=0; j<i; j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

int main()
{
    // int n=2; //o/p: 2
    int n=3; //o/p: 5
    // int n=4; //o/p: 14
    // int n=5; //o/p: 42

    cout << countBSTs(n) << endl;

    return 0;
}