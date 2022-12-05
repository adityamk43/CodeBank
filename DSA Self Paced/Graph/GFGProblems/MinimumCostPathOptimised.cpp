/**
 * @file MinimumCostPathOptimised.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Minimum Cost Path
HardAccuracy: 26.99%Submissions: 56785Points: 8
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).

Note: It is assumed that negative cost cycles do not exist in the input matrix.


Example 1:

Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Example 2:

Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.


Your Task:
You don't need to read or print anything. Your task is to complete the function minimumCostPath() which takes grid as input parameter and returns the minimum cost to react at bottom right cell from top left cell.


Expected Time Compelxity: O(n2*log(n))
Expected Auxiliary Space: O(n2)


Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 1000
 *
 * @version 0.1
 * @date 2022-12-05 07:13 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> myPair;

class Solution
{
public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    bool isValid(vector<vector<int>> &grid, int rows, int cols, int i, int j)
    {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int rows = grid.size();
        int cols = grid[0].size();

        bool finalised[rows][cols];
        int dist[rows][cols];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                dist[i][j] = INT_MAX;

        set<pair<int, myPair>> st;
        st.insert({0, {0, 0}});
        dist[0][0] = grid[0][0];

        while (!st.empty())
        {
            auto cur = *st.begin();
            st.erase(st.begin());

            for (int k = 0; k < 4; k++)
            {
                int x = cur.second.first + dx[k];
                int y = cur.second.second + dy[k];

                if (
                    isValid(grid, rows, cols, x, y) && dist[x][y] > dist[cur.second.first][cur.second.second] + grid[x][y])
                {
                    if (dist[x][y] != INT_MAX)
                        st.erase(st.find({dist[x][y], {x, y}}));

                    dist[x][y] = dist[cur.second.first][cur.second.second] + grid[x][y];

                    st.insert({dist[x][y], {x, y}});
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends