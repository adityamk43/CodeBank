/**
 * @file XTotalShapes.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * X Total Shapes
MediumAccuracy: 65.94%Submissions: 36029Points: 4
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).


Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation:
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there are 3 different groups
in the given grid.

Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1
Expanation:
The grid is-
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.


Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.


Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)


Constraints:
1 ≤ n, m ≤ 100
 *
 * @version 0.1
 * @date 2022-12-05 07:14 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the number of 'X' total shapes.
    void DFS(vector<vector<char>> &grid, int i, int j, int rows, int cols, int dx[], int dy[])
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 'O')
            return;

        grid[i][j] = 'O';

        int u, v;
        for (int k = 0; k < 4; k++)
        {
            u = i + dx[k];
            v = j + dy[k];

            DFS(grid, u, v, rows, cols, dx, dy);
        }
    }

    int xShape(vector<vector<char>> &grid)
    {
        // Code here
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int count = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 'X')
                {
                    count++;

                    DFS(grid, i, j, rows, cols, dx, dy);
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.xShape(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends