/**
 * @file DistanceofNearestCellHaving1.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Distance of nearest cell having 1
MediumAccuracy: 47.7%Submissions: 31930Points: 4
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.


Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.


Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.




Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
 *
 * @version 0.1
 * @date 2022-12-05 07:16 PM
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
    // Function to find distance of nearest 1 in the grid for each cell.
    int BFS(vector<vector<int>> &grid, int i, int j, int dx[], int dy[])
    {

        queue<pair<int, int>> q;

        q.push({i, j});

        while (!q.empty())
        {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            if (grid[u][v] == 1)
                return (abs(i - u) + abs(j - v));

            for (int k = 0; k < 4; k++)
            {
                int x = u + dx[k];
                int y = v + dy[k];

                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
                    q.push({x, y});
            }
        }
    }

    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), 0));
        // vector<vector<int>> dis;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                dis[i][j] = BFS(grid, i, j, dx, dy);
            }
        }

        return dis;
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
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends