/**
 * @file OptimalStrategy.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * In this problem, we are given an array of random values and two players are playing a game in which one person can only pick corner values of the array. Both players are considered playing optimally and first player(you) always pick first from array.
 * 
 * Example:
 * 
 * 20, 5, 4, 6
 * 
 * O/P: 25
 * 
 * 1st: 20
 * 2nd: 6
 * 1st: 5
 * 2nd: 4
 * 
 * 1st Player score -> 25
 * 
 * Example 2:
 * 
 * 2, 3, 15, 7
 * 
 * O/P: 17
 * 
 * 1st: 2
 * 2nd: 7
 * 1st: 15
 * 2nd: 3
 * 
 * 1st Player score -> 17
 * 
 * @version 0.1
 * @date 2022-12-22 10:52 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief If we not look by optimally then we can say that another version of this problem can be picking higher value from the given array. That can be done using greedy approach and in a way that we can either choose odd placed values if they have highest values or even placed values if they are higher, then in this way also 1st player can win. But this solution will not give us the optimal and maximum value.
 * 
 * Let's see now 2 recursion solutions and D.P. solution for finding optimal solution for this problem!!
 * 
 */

/**
 * @brief 
 * 1st RECURSION SOLUTION:
 * 
 * This solution makes the use of sum value of values in array from mainSol function. Then it finds the maximum solution that opponent player can gain and subtract this value from the total sum and we get 1st player Optimal/Maximum Value.
 * 
 * NOTE: The problem with this solution is that making it into D.P. solution could cause a lot auxiliary space due to the sum variable. We will have 3 parameters that are changing: i, j, sum and sum can vary upto very much higher values depending upon the values inside the array.
 * 
 * So, 2nd Recursive solution will solve this problem by not using sum variable and we will create tabulation D.P. solution of the 2nd Recursive Solution.
 * 
 * @param arr 
 * @param i 
 * @param j 
 * @param sum 
 * @return int 
 */
// int sol(int arr[], int i, int j, int sum)
// {
//     if (i+1==j)
//         return max(arr[i], arr[j]);
    
//     return max(
//         sum - sol(arr, i+1, j, sum-arr[i]),
//         sum - sol(arr, i, j-1, sum-arr[j])
//     );
// }

// int mainSol(int arr[], int n)
// {
//     int sum=0;

//     //this will find sum of all values in the array
//     for (int i=0; i<n; i++)
//         sum+=arr[i];

//     return sol(arr, 0, n-1, sum);
    
// }

/**
 * @brief 2nd RECURSIVE SOLUTION:
 *  
 * In this solution, since we are not finding sum value, so what we are doing is that, we know that opponent is also playing optimally so at opponent's turn he will play optimally so, we will get minimum value after opponent's pick. So we will add it to our pick and then find max of different choices as done below.
 * 
 * Here, only two parameters are changing: i, j and there is no variable like sum which can vary upto very long values, thus we can make D.P. Tabulation solution from this recursion solution.
 * 
 * @param arr 
 * @param i 
 * @param j 
 * @return int 
 */
// int sol(int arr[], int i, int j)
// {
//     if (i+1==j)
//         return max(arr[i], arr[j]);
    
//     return max(
//         arr[i] + min(sol(arr, i+2, j), sol(arr, i+1, j-1)),
//         arr[j] + min(sol(arr, i+1, j-1), sol(arr, i, j-2))
//     );
// }

// int mainSol(int arr[], int n)
// {
//     return sol(arr, 0, n-1);
// }

/**
 * @brief D.P. TABULATION SOLUTION
 * 
 * From 2nd recursive approach, we inferred that for block of dp[i][j], it needs value from dp[i+2][j], dp[i+1][j-1], dp[i][j-2] which are diagonal elements with one diagonal space below, which means these are the 2nd diagonal elements below dp[i][j]. Using these analysis, we traverse accordingly as we want to fill these diagonal elements first in order to fill dp[i][j].
 * 
 * We take gap variable which will maintain diagonal alternate spacing consideration.
 * 
 * And we will get our value at block dp[0][n-1] as i=0 and j=n-1 means we have traversed whole array according to the 2nd recursive solution approach!! 
 * NOTE: [If we take analysis of how 2nd recursion is working then it will be easy to understand how at this block the answer will come and why we need diagonal elements..]
 * 
 * TIME COMPLEXITY: ⊝(n^2)
 * AUXILIARY SPACE: ⊝(n^2)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int mainSol(int arr[], int n)
{
    int dp[n][n];

    for (int i=0; i<n-1; i++)
        dp[i][i+1] = max(arr[i], arr[i+1]);

    for (int gap=3; gap<n; gap+=2)
    {
        for (int i=0; i+gap<n; i++)
        {
            int j=i+gap;

            dp[i][j] = max(
                        arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
                        arr[j] + min(dp[i+1][j-1], dp[i][j-2])
                    );
        }
    }

    return dp[0][n-1];
}

int main()
{
    //EXAMPLE 1
    int arr[] = {20, 5, 4, 6};
    
    // EXAMPLE 2
    // int arr[] = {2, 3, 15, 7};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << mainSol(arr, n) << endl;

    return 0;
}

