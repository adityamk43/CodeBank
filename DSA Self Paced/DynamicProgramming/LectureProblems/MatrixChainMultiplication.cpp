/**
 * @file MatrixChainMultiplication.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * We are given an array which contains dimensions of matrices and we want to find the minimum number of multiplications needed to multiply these matrices with each other.
 *      
 *        M1  M2  M3  
 *       / \ / \ / \ 
 * Eg: {2,  1,  3,  4}
 * 
 * M1(2x1), M2(1x3), M3(3x4)
 * 
 * First Case:
 * (M1 x (M2xM3)) = 0 + 1x3x4 + 2x1x4 = 20 Multiplications
 * 
 * Second Case:
 * ((M1xM2) x M3) = 2x1x3 + 0 + 2x3x4 = 30 Multiplications
 * 
 * So, the minimum is First Case with only 20 multiplications
 * 
 * BACKGROUND:
 * How matrix multiplications works?
 * 
 * A(3x4) * B(4x5) = C(3x5)
 * 
 * Now, the number of integer multiplications = 3x4x5
 * 
 * Assuming we multiplied each element of rows of first matrix with each elements of columns in second matrix.
 * 
 * So, in total for the above example we need 4 multiplications for each rows(1st Matrix) and columns(2nd Matrix) to create C(3x5) matrix from A and B Matrix.
 * 
 * So, total 3x4x5 multiplications!!
 * 
 * NOTE: For C matrix's first row, first column element we do,
 * 
 * a1*b1 + a2*b6 + a3*b11 + a4*b16, 4 multiplications for one element,
 * Thus 3x4x5 multiplications for 3x5 elements of C Matrix!!
 * 
 * 
 *         M1   M2   M3             Mn-1
 *       /   \ /  \ /  \           /    \
 * Eg: {a0,  a1,  a2,  a3 ..... an-2,   an-1}
 * 
 * So, for array of size n, there can be total n-1 Matrices that can be formed!
 * 
 * => Different Ways to make first partition:
 *  
 * 1.) (M1) x (M2xM3.....Mn-1) => (a0 a1) (a1 a2..... an-1)
 * 2.) (M1xM2) x (M3xM4.....Mn-1) => (a0 a1 a2) (a2 a3..... an-1)
 * 3.) (M1xM2xM3) x (M4xM5.....Mn-1) => (a0 a1 a2 a3) (a3 a4..... an-1)
 *                                   Recursive      Recursive
 *                                     Call           Call
 * 
 * So, if you are given a Matrix chain of n-1 as array size is n, then there are n-2 ways for making first partition if the chain length is n-1
 * 
 * So, if your first partition is M1
 * then 2nd partition (M1xM2)
 * till (M1xM2x...Mn-2)
 * 
 * thus, n-2 ways. 
 * 
 * @version 0.1
 * @date 2022-12-26 07:52 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION WITH OVERLAPPINGS
 * 
 * TIME COMPLEXITY: EXPONENTIAL
 * 
 * @param arr 
 * @param i 
 * @param j 
 * @return int 
 */
// int mChain(int arr[], int i, int j)
// {
//     if (i+1==j)
//         return 0;
    
//     int res=INT_MAX;

//     for (int k=i+1; k<j; k++)
//         res = min(res, mChain(arr, i, k) + mChain(arr, k, j) + arr[i]*arr[k]*arr[j]);
    
//     return res;
// }

// int mChainSol(int arr[], int n)
// {
//     return mChain(arr, 0, n-1);
// }

/**
 * @brief D.P. TABULATION TECHNIQUE
 * 
 * TIME COMPLEXITY: O(n^3)
 * AUXILIARY SPACE: ⊝(n^2)
 * 
 * Since, two parameters that are changing are i and j which can go upto n.
 * Thus, dp size will be dp[n][n]
 * 
 * and from recursion, we can infere that our answer will be in the block dp[0][n-1]
 * 
 * and the filling of matrix will be different as we do from col to col for each row as for each cell of dp[i][j], we would need
 * [say i=0, j=3]
 * dp[0][1], dp[0][2]
 * dp[1][3], dp[2][3]
 * 
 * So, we will fill the matrix similar to the way we did for optimal strategy implementation.
 * 
 * NOTE: Some of the matrix cell will be empty where i>=j as will only fill those cell where i<j!!
 * 
 * @param arr 
 * @param i 
 * @param j 
 * @return int 
 */
int mChainSol(int arr[], int n)
{
    int dp[n][n];

    for (int i=0; i<n-1; i++)
        dp[i][i+1] = 0;

    int gap;
    for (gap=2; gap<n; gap++)
    {
        for (int i=0; i+gap<n; i++)
        {
            int j=i+gap;
            dp[i][j] = INT_MAX;

                for (int k=i+1; k<j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
                }
        }
    }

    return dp[0][n-1];
}

int main()
{
    //EXAMPLE 1
    int arr[] = {2, 1, 3, 4};

    //EXAMPLE 2
    // int arr[] = {20, 10, 30, 40};
    
    //EXAMPLE 3
    // int arr[] = {2, 1, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << mChainSol(arr, n) << endl;

    return 0;
}