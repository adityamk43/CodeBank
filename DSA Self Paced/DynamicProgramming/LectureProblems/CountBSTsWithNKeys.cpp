/**
 * @file CountBSTsWithNKeys.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given a total number of keys and we need to find that how many number of bsts can be made from these number of keys. Value of keys can by any random numbers.
 * 
 * The idea is that when analysing the answer for this solution we see that for 0, 1, 2, 3 keys, we have 1, 1, 2, 5 number of unique BSTs respectively.
 * 
 * Now, for n=4 keys and onwards, we see that the pattern in which the value we get is in the form
 * 
 * res(n) = res(0)*res(n-1) + res(1)*res(n-2) + ..... + res(n-1)*res(0)
 *        = i=0 £ n-1 res(i)*res(n-i-1)
 * 
 * How, do we get this series?
 * Refer https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-DP/video/NzQyNw%3D%3D for derivation and idea to get clear understanding!! 
 * 
 * IMPORTANTNOTE: THERE IS AN INTERESTING FACT ABOUT THIS PROBLEM, IT'S AN APPLICATION OF CATALAN NUMBERS.
 * 
 * THE RESULT OF N INPUT IS ACTUALLY Nth CATALN NUMBER.
 * 
 * FORMULA FOR Nth CATALAN NUMBER IS:
 * 
 * res(n) = 1/(n+1) * 2nCn
 * 
 * eg:
 * res(0) = 1
 * 
 * res(1) = 1/2 * 2C1 = 1
 * 
 * res(2) = 1/3 * 4C2 = 1/3 * 4!/(2!*2!) = 2
 * 
 * res(3) = 1/4 * 6C3 = 1/4 * 6!/(3!*3!) = 20/4 = 5
 * 
 * NOTE: THE Nth CATLAN Number solution is given in GFG Problems. Please refer to that solution for TIME COMPLEXITY: O(N) and AUXILIARY SPACE: O(N).
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
//     for n=0, we can create an empty root(NULL) BST, thus for n=0 we also return 1 
//     if (n==0 || n==1)
//         return 1;
    
//     int res=0;
//     for (int i=1; i<=n; i++)
//         res+=countBSTs(i-1)*countBSTs(n-i);
    
//     return res;
// }

/**
 * @brief D.P. TABULATION TECHNIQUE
 * 
 * TIME COMPLEXITY: O(n^2)
 * AUXILIARY SPACE: ⊝(n)
 * 
 * @param n 
 * @return int 
 */
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