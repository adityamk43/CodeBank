/**
 * @file SudokuProblem.cpp
 * @author ADITYA BHARDWAJ
 * @brief This is the most popular game. We used to sove these in newspapers and arcade games.
 *
 * I am assuming that everybody knows rules of sudoku otherwise you can search it online, they are pretty simple rules!
 *
 * @version 0.1
 * @date 2022-12-11 10:02 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <math.h>
using namespace std;
#define N 9

void printSol(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int grid[N][N], int x, int y, int value)
{
    for (int i = 0; i < N; i++)
        if (grid[x][i] == value || grid[i][y] == value)
            return false;

    // int k = sqrt(N);
    int k = (int)sqrt(N);

    int row_start = x - (x % k);
    int col_start = y - (y % k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (grid[i + row_start][j + col_start] == value)
                return false;

    return true;
}

bool solveSudokuRec(int grid[N][N])
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    if (isEmpty)
    {
        return true;
    }

    for (int k = 1; k <= N; k++)
    {
        if (isSafe(grid, row, col, k))
        {
            grid[row][col] = k;

            if (solveSudokuRec(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

/**
 * @brief
 *
 *  TIME COMPLEXITY: O(9^(N*N)), For every unassigned index, there are 9 possible options so the time complexity is O(n^(n*n)).
 *
 *  AUXILIARY SPACE: O(N*N), To store the output array a matrix is needed.
 *
 * @param grid
 */
void solveSudoku(int grid[N][N])
{
    if (solveSudokuRec(grid))
    {
        cout << "Sudoku is Solved!! " << endl;
        printSol(grid);
    }
    else
        cout << "Sudoku with the given grid cannot be solved!!" << endl;
}

int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(grid);

    return 0;
}