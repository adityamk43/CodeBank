/*EFFICIENT CODE COMMENTED (MY IMPLEMENTED CODE HAS MORE AUXILIARY SPACE THAN THE EFFICIENT ONE i.e., O(N*N) > O(1) 

Algorithm: Traverse the given matrix row by row, and copy the elements of ith row into the N-i-1 column of the resultant matrix.

MY IMPLEMENTED CODE:

Time Complexity: O(N*N); the given matrix is traversed only once

Space Complexity: O(N*N); we used an auxiliary matrix to store the result

EFFICIENT SOLUTION:

Algorithm:

Transpose the given matrix i.e. flip the matrix over its diagonal.
    We can transpose a matrix by switching its rows with its columns i.e. by interchanging the elements at position (i, j) with (j, i)
    Traverse only one half of the matrix i.e. the upper right half. For that run two nested loops, the outer loop from 0 to N and inner loop from 0 to index of the outer loop. Then for each i, j swap(mat[i][j], mat[j][i]).
After the transpose, reverse the rows of the transposed matrix.
Time Complexity: O(N*N); the given matrix is traversed twice

Space Complexity: O(1); no auxiliary space is required

*/

/*
#include <iostream>
using namespace std;

#define N 4

void reverseColumns(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            swap(arr[i][j], arr[i][N-j-1]);
}
 
void transposeMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            swap(arr[i][j], arr[j][i]);
}

void rotateMatrix(int mat[N][N])
{
    	transposeMatrix(mat);
	reverseColumns(mat);
}

void displayMatrix(int mat[N][N])
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << mat[i][j] << "\t";
		cout << "\n";
	}

	cout << "\n";
}

int main()
{
	int mat[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	displayMatrix(mat);

	rotateMatrix(mat);

	displayMatrix(mat);

	return 0;
}
*/

/* add c++ headers if necessary*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define ROWS 50
#define COLS 50

using namespace std;

void RotateNinety(int arr[ROWS][COLS], int n)
{
  int transpose[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      transpose[i][j] = arr[n - 1 - j][i];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j > 0)
      {
        cout << " ";
      }

      cout << transpose[i][j];
    }

    cout << endl;
  }
}

int main()
{
  int n, T;
  int arr[ROWS][COLS];

  cin >> T;
  while (T > 0)
  {
    cin >> n;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> arr[i][j];

    RotateNinety(arr, n);

    cout << endl;

    T--;
  }

  return 0;
}
/* add tail for c++ if necessary*/