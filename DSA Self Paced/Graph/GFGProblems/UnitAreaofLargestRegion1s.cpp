/**
 * @file UnitAreaofLargestRegion1s.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Unit Area of largest region of 1's
MediumAccuracy: 50.83%Submissions: 53239Points: 4
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).


Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n, m ≤ 500
 *
 * @version 0.1
 * @date 2022-12-05 07:18 PM
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
    // Function to find unit area of the largest region of 1s.
    void DFS(vector<vector<int>> &grid, int i, int j, int &count, int dx[], int dy[])
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;

        count++;
        grid[i][j] = 0;

        for (int k = 0; k < 8; k++)
        {
            int u = i + dx[k];
            int v = j + dy[k];

            DFS(grid, u, v, count, dx, dy);
        }
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int dx[] = {1, -1, 1, 1, -1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        int res = INT_MIN;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int count = 0;

                if (grid[i][j] == 1)
                    DFS(grid, i, j, count, dx, dy);

                res = max(res, count);
            }
        }

        return res;
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
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends