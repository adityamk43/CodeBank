/*
DIAGONAL TRAVERSING
*/
// #include <bits/stdc++.h>
// using namespace std;

// #define N 10

// /*
//  * Complete the 'counterDiagonal' function below.
//  * Print the counter diagonal traversal of the matrix, seperated by space
//  * @params
//  *   mat -> square matrix of size (n x n)
//  *   n -> integer denoting size of square matrix
//  */
// void counterDiagonal(int mat[N][N], int n)
// {
//   // Write your code here
//   for (int col = n-1; col >= 0; col--)
//   {
//     int i = 0, j = col;

//     while (i < n && j < n)
//     {
//       cout << mat[i][j] << " ";
//       i++;
//       j++;
//     }
//   }

//   for (int row = 1; row < n; row++)
//   {
//     int i = row, j = 0;

//     while (i < n && j < n)
//     {
//       cout << mat[i][j] << " ";
//       i++;
//       j++;
//     }
//   }
// }
// int main()
// {
//   int n;
//   cin >> n;
//   int mat[N][N];
//   for (int i = 0; i < n; i++)
//     for (int j = 0; j < n; j++)
//       cin >> mat[i][j];

//   counterDiagonal(mat, n);

//   return 0;
// }

/*
ANTI-DIAGONAL/COUNTER-DIAGONAL TRAVERSING
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10

/*
 * Complete the 'counterDiagonal' function below.
 * Print the counter diagonal traversal of the matrix, seperated by space
 * @params
 *   mat -> square matrix of size (n x n)
 *   n -> integer denoting size of square matrix
 */
void counterDiagonal(int mat[N][N], int n)
{
  // Write your code here
  for (int col = 0; col < n; col++)
  {
    int i = 0, j = col;

    while (i < n && j >= 0)
    {
      cout << mat[i][j] << " ";
      i++;
      j--;
    }
  }

  for (int row = 1; row < n; row++)
  {
    int i = row, j = n - 1;

    while (i < n && j >= 0)
    {
      cout << mat[i][j] << " ";
      i++;
      j--;
    }
  }
}
int main()
{
  int n;
  cin >> n;
  int mat[N][N];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];

  counterDiagonal(mat, n);

  return 0;
}