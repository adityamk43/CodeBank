/**
 * @file NthFibonacciMemoization.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 *                              Introduction to Dynamic Programming
 * 
 * Dynamic Programming in very simple words is an optimisation over plain recursion problems.
 * 
 * Dynamic Programming is an algorithmic approach to solve some complex problems easily and save time and number of comparisons by storing the results of past computations. The basic idea of dynamic programming is to store the results of previous calculation and reuse it in future instead of recalculating them.

We can also see Dynamic Programming as dividing a particular problem into subproblems and then storing the result of these subproblems to calculate the result of the actual problem. (when there are overlapping(same) subproblems).

There are two ways to implement DP:

1.) Memoization (Top-Down)
2.) Tabulation (Bottom-up)

Applications:

1.) Bellman Ford Algorithm
2.) Floyd Warshall Algorithm
3.) Diff Utility (LCS) Ex: Git, we find difference between two files and commit if there are any changes or modifications.
4.) Search closed words (Edit Distance)
5.) Resource Allocation (0-1 Knapsack)
.
.
.
so on..

IMPORTANTNOTE: Below is an example of Memoization for Nth Fibonacci Numbers.
NOTE: Memoization advantage over Tabulation is that it is easy to understand and implement over Tabulation as we can first implement plain recursion and see which subproblems are overlapping and produce memoization array for same.

Tabulation advantage is discussed in Tabulation Nth Fibonnaci Code.


NOTE: This is not the best solution for Nth Fibonacci, fibonacci is used as a basic example to help to discuss and understand Dynamic Programming (DP).

Its best solution is provided usind matrix multiplication which gives optimal time complexity of ⊖(logN)

DYNAMIC PROGRAMMING name is not related to dynamic memory by any sense, its just a random name given to these types of algorithms and solutions!!
 * 
 * @version 0.1
 * @date 2022-12-17 08:52 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Nth Fibonnaci using Plain Recursion
 * 
 * TIME COMPLEXITY: ⊖(2^n)
 * AUXILIARY SPACE: ⊖(n)
 * 
 * @param n 
 * @return long long int 
 */
// long long int fib(int n)
// {
//     if (n<=1)
//         return n;
    
//     return fib(n-1) + fib(n-2);
// }

/**
 * @brief TIME COMPLEXITY: n fun calls + n-1 fun calls = 2n-1 function calls
 * 
 * Each function does ⊖(1) work
 * 
 * EXAMPLE:
 *                        fib(5)
 *                      /       \
 *                  fib(4)     fib(3)
 *                /      \
 *             fib(3)   fib(2)
 *            /    \
 *        fib(2)   fib(1)
 *       /     \
 *    fib(1)  fib(0)
 * 
 * n + n-1 => 2n-1 recursive calls!!
 * 
 * so ⊖(n) linear work using Memoization Dynamic Programming.
 * 
 * AUXILIARY SPACE: ⊖(n) for function calls stack and memo array. 
 * 
 * NOTE: We are doing Top-down using Recursion hence, it is called memoization technique. Tabulation/Bottom-up is discussed in other code!
 * 
 * @param n 
 * @param memo 
 * @return long long int 
 */
long long int fib(long long int n, long long int memo[])
{
    if (memo[n] == -1)
    {
        long long int res;

        if (n==0 || n==1)
            res = n;
        
        else
            res= fib(n-1, memo) + fib(n-2, memo);

        memo[n] = res;
    }

    return memo[n];
}

int main()
{
    long long int n;
    cin >> n;

    long long int memo[n+1];

    memset(memo, -1, sizeof(memo));

    cout << fib(n, memo) << endl;

    return 0;
}
