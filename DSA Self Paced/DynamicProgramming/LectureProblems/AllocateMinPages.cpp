/**
 * @file AllocateMinPages.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * This is a popular interview question.
 * 
 * 1.) We are given an array with different elements as pages of different books.
 * 2.) And we are given a variable which tells us about the number of students who wants to read those books.
 * 
 * The task is:
 * 
 * 1.) Minimize the maximum pages allocated.
 * 2.) Only contagious pages can be allocated
 * 
 * NOTE: Each Students read atleast one book.
 * 
 * Explanation: 
 * 
 * x0 | x1 | x2 | x3 | ....... xi-1 | xi | ...... | xn-1
 * 
 * We need to choose  (K-1) cuts out of (n-1) cuts given above. 
 * 
 * So, total ways:
 *  n-1 C K-1
 * 
 * Example: 
 * 
 * [ 10, 20, 30, 40]
 * K=2
 * 
 * We need to choose 1 cut out of 3 cuts
 * 
 * 
 * @version 0.1
 * @date 2023-02-12 08:26 PM
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief utility sum function for below function
 * 
 * @param arr 
 * @param b 
 * @param e 
 * @return int 
 */
int sum(int arr[], int b, int e)
{
    int sum=0;
    for (int i=b; i<=e; i++)
        sum+=arr[i];
    
    return sum;
}

/**
 * @brief NAIVE SOLUTION
 * 
 * TIME COMPLEXITY: Exponential as we check all possibilities through recursion
 * 
 * x0 | x1 | x2 | x3 | ....... xi-1 | xi | ...... | xn-1
 * |                                |
 * ------------- i -----------(first cut)
 * 
 * We assume that first student read books from xi to xn-1 and we sum these books pages
 * 
 * and the other remaining K-1 students read the above given i books. So, we recursively call function for those i books and K-1 students to find the Minimum Pages a student can read which will find through minimizing the maximum pages allocated to each students.
 * 
 * 
 * NOTE: Each Students read atleast one book.
 * 
 * @param arr 
 * @param n 
 * @param K 
 * @return int 
 */
// int minPages(int arr[], int n, int K)
// {
//     //If there is only one students then he will read all the books
//     if (K==1)
//         return sum(arr, 0, n-1);
    
//     //if there is only one book then we return that book only!
//     if (n==1)
//         return arr[0];

//     int res = INT_MAX;

//     for (int i=1; i<n; i++)
//         res = min(res, max(minPages(arr, i, K-1), sum(arr, i, n-1)));

//     return res;

// }

/**
 * @brief D.P. SOLUTION
 * 
 * If you draw recursion tree for above solution, we will notice that there are some overlapping subproblems, so we optimise the above solution using Dynamic Programming.
 * 
 * TIME COMPLEXITY: O(n^3 K)
 * AUXILIARY SPACE: ⊝(nK)
 * 
 * NOTE: We can reduce the time complexity to O(n^2 K), if we precompute the sum using 2D array and lookup in that array for dp solution.
 * But it will also increase Aux Space as Precomputed Sum 2D array will take nxn space!!
 * 
 * IMPORTANT_NOTE: The Better solution is present rather than D.P. which is a Binary Search based solution which takes O(nlogsum) Time Complexity.
 * 
 * Binary Search Solution depends upon sum function, so it may happen that for large values of sum, it's solution may become slower than this D.P. based solution.
 * 
 * @param arr 
 * @param n 
 * @param K 
 * @return int 
 */
int minPages(int arr[], int n, int K)
{ 
    int dp[K+1][n+1];

    //O(n)
    for (int i=1; i<=n; i++)
        dp[1][i] = sum(arr, 0, i-1);

    //O(K)
    for (int j=1; j<=K; j++)
        dp[j][1] = arr[0];

    //O(K*n*n*n) Since, sum function also takes n linear space
    for (int i=2; i<=K; i++)
    {
        for (int j=2; j<=n; j++)
        {
            int res = INT_MAX;

            for (int p=1; p<j; p++)
                res = min(res, max(dp[i-1][p], sum(arr, p, j-1)));
            
            dp[i][j]=res;
        }
    }

    return dp[K][n];

}


int main()
{
    //EXAMPLE 1 -> O/P: 60
    //10 20 30  | 40
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int K=2;

    //EXAMPLE 2 -> O/P: 60
    // int arr[] = {10, 20, 30};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int K=1;
    
    //EXAMPLE 3 -> O/P: 30
    //10 5 | 30 | 1 2 5 10 10
    // int arr[] = {10, 5, 30, 1, 2, 5, 10, 10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int K=3;

    cout << "Minimum Pages Allocated is: " << endl;
    cout << minPages(arr, n, K) << endl;

    return 0;
}