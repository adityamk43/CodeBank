/**
 * @file NQueenProblem.cpp
 * @author ADITYA BHARDWAJ
 * @brief We are given NxN Chess Board and we need to ensure that no N Queens should cut each other vertically, diagonally, or horizontally.
 * 
 * @version 0.1
 * @date 2022-12-11 09:30 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;
#define N 4

int chessBoard[N][N];

void printSol(int chessBoard[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << chessBoard[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col)
{
    for (int i=0; i<col; i++)
        if (chessBoard[row][i] == 1)
            return false;
    
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (chessBoard[i][j] == 1)
            return false;

    for (int i=row, j=col; i<N && j>=0; i++, j--)
        if (chessBoard[i][j] == 1)
            return false;
        
    return true;
}

bool solveNQueen(int col)
{
    if (col == N)
        return true;
    
    for (int i=0; i<N; i++)
    {
        if (isSafe(i, col))
        {
            chessBoard[i][col]=1;
            if (solveNQueen(col+1))
                return true;
            chessBoard[i][col]=0;
        }

    }

    return false;
}

/**
 * @brief 
 * TIME COMPLEXITY: O(N!)
 * AUXILIARY SPACE: O(N^2)
 * 
 */
void solve()
{   
    if (solveNQueen(0))
    {
        cout << "N Queen Solution for given ChessBoard is: " << endl;
        printSol(chessBoard);
    }
    else
        cout << "No N Queen solution exists for this given ChessBoard!!" << endl;

}

int main()
{
    solve();
    return 0;
}