/**
 * @file MaximumCuts.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * In this problem, we are given one wood log/rope and 3 values and we have to find in maxicum cuts we can make using these values only (cuts should be made using given 3 values and not some random values!!).
 * 
 * @version 0.1
 * @date 2022-12-20 01:28 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief 
 *      PLAIN RECURSION
 * 
 *       TIME COMPLEXITY: O(3^n)
 *       AUXILIARY SPACE: O(n)
 * 
 * @param n 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
/*
int maxCuts(int n, int a, int b, int c)
{
    if (n==0)
        return 0;
    
    if (n<0)
        return -1;
    
    int res = max(maxCuts(n-a, a, b, c),
                max(maxCuts(n-b, a, b, c),
                maxCuts(n-c, a, b, c)));  

    if (res==-1)
        return -1;
    
    return res+1;

}
*/

/**
 * @brief 
 * Using D.P. Tabulation 
 * 
 *        TIME COMPLEXITY: ⊝(n)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * @param n 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int maxCuts(int n, int a, int b, int c)
{
    int dp[n+1];

    dp[0] = 0;

    for (int i=1; i<=n; i++)
    {
        dp[i]=-1;

        if (i-a>=0)
            dp[i] = max(dp[i], dp[i-a]);
        if (i-b>=0)
            dp[i] = max(dp[i], dp[i-b]);
        if (i-c>=0)
            dp[i] = max(dp[i], dp[i-c]);
        
        if (dp[i]!=-1)
            dp[i]++;
        
    }

    return dp[n];
}

int main()
{  
    //EXAMPLE 1
    int n=5;
    int a=1, b=2, c=3;

    //EXAMPLE 2
    // int n=23;
    // int a=12, b=11, c=13;

    //EXAMPLE 3
    // int n=3;
    // int a=2, b=4, c=2;

    cout << maxCuts(n, a, b, c) << endl;

    return 0;
}

