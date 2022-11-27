/**
 * @file NumberOfIslands.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 *  Find the number of islands
MediumAccuracy: 42.12%Submissions: 100k+Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.  

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
 * 
 * I/P.
 *  4 2
    0 1
    1 0
    1 1
    1 0
 * Input Format:
First line should contain n and m. Each of next n line should contain m space separated characters(either '1' or '0').

Example:

4 2
0 1
1 0
1 1
1 0
 * 
 * @version 0.1
 * @date 2022-11-27 07:19 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */

//{ Driver Code Starts
// import java.util.*;
// import java.lang.*;
import java.io.*;

class NumberOfIslands {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S[j].charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.numIslands(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Solution {
    // Function to find the number of islands.
    public void findIsland(char[][] grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
            return;

        grid[i][j] = '2';

        findIsland(grid, i + 1, j, rows, cols);
        findIsland(grid, i - 1, j, rows, cols);
        findIsland(grid, i, j + 1, rows, cols);
        findIsland(grid, i, j - 1, rows, cols);
        findIsland(grid, i + 1, j - 1, rows, cols);
        findIsland(grid, i + 1, j + 1, rows, cols);
        findIsland(grid, i - 1, j - 1, rows, cols);
        findIsland(grid, i - 1, j + 1, rows, cols);
    }

    public int numIslands(char[][] grid) {
        // Code here
        int rows = grid.length;
        int cols = grid[0].length;

        int numOfIslands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    findIsland(grid, i, j, rows, cols);
                    numOfIslands++;
                }
            }
        }

        return numOfIslands;

    }
}