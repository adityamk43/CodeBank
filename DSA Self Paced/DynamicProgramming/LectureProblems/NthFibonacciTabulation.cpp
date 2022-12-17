/**
 * @file NthFibonacciTabulation.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 *                             Introduction to Dynamic Programming
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
 * 
 * In this code, we will follow Tabulation D.P. appraoch to solve Nth Fibonnaci.
 * 
 * In Memoization we were using Recursion to find the solution in a Top-Down manner.
 * 
 * Here we will find solution in Bottom-up manner meaning we will start from 0th fibonacci to find the value for given Nth Fibonacci.
 * 
 * Time Complexity and Auxiliary Space of both Techniques, Memoization and Tabulation is same except there will be drawback of function overhead calls in Memoization due to recursive function calls and thus faster than memoization!!
 * 
 * NOTE: This is not the best solution for Nth Fibonacci, fibonacci is used as a basic example to help to discuss and understand Dynamic Programming (DP).

Its best solution is provided usind matrix multiplication which gives optimal time complexity of ⊖(logN)

DYNAMIC PROGRAMMING name is not related to dynamic memory by any sense, its just a random name given to these types of algorithms and solutions!!
 * 
 * @version 0.1
 * @date 2022-12-17 09:47 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief TIME COMPLEXITY: ⊖(n), iterative loop runs till n
 *        AUXILIARY SPACE: ⊖(n), for array to store fib values
 * 
 * @param n  
 * @return long long int 
 */
long long int fib(long long int n)
{
    long long int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}

int main()
{
    long long int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}
