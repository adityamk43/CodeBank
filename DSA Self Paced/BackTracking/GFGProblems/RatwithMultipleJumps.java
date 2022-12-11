/**
 * @file RatwithMultipleJumps.java
 * @author ADITYA BHARDWAJ
 * @brief 
 *                          Rat Maze With Multiple Jumps
MediumAccuracy: 27.68%Submissions: 10K+Points: 4
A Maze is given as N*N matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. Find if it is possible for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].

Note:
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].

Example 1:

Input:
N = 4
maze[][] = {{2,1,0,0},{3,0,0,1},
{0,1,0,1},{0,0,0,1}}
Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
Explanation: Rat started with m[0][0] and
can jump up to 2 steps right/down. First
check m[0][1] as it is 1, next check
m[0][2], this won't lead to the solution.
Then check m[1][0], as this is 3(non-zero)
so we can make 3 jumps to reach m[1][3].
From m[1][3] we can move downwards taking
1 jump each time to reach destination at
m[3][3]. 
Example 2:

Input:
N = 4
maze[][] = {{2,1,0,0}{2,0,0,1},
{0,1,0,1},{0,0,0,1}}
Output: -1
Explanation: As no path exists, so -1.
Your task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes the Maze and its dimensions N as inputs and prints the valid path if it exists. If it does not exist, print -1
Note: In the valid path, for each block, if you are visiting the block then you should print 1 for it else 0. 

Expected Time Complexity: O(NN).
Expected Auxiliary Space: O(N) if we don't consider the solution matrix for this.

Constraints:
2 <= n <= 50
0 <= maze[i][j] <= 20
 * 
 * @version 0.1
 * @date 2022-12-11 09:27 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
import java.util.*;
// import java.lang.*;
// import java.io.*;

public class RatwithMultipleJumps {
    public static int N = 0;

    public static void main(String[] args) {
        // code
        Scanner a = new Scanner(System.in);
        int T = a.nextInt();
        for (int z = 0; z < T; z++) {
            N = a.nextInt();

            int[][] maze = new int[N][N];
            for (int y = 0; y < N; y++) {
                for (int o = 0; o < N; o++)
                    maze[y][o] = a.nextInt();
            }

            RatInMaze.solve(maze, N);
        }
        a.close();
    }

    public static void print(int N, int[][] sol) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(sol[i][j] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends

class RatInMaze {
    // Function to find the minimum number of Hops required for the rat to
    // reach from the source block to the destination block.
    public static void printSolution(int sol[][], int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(sol[i][j] + " ");
            System.out.println();
        }
    }

    public static boolean isSafe(int maze[][], int i, int j, int N) {
        return (i >= 0 && j >= 0 && i < N && j < N && maze[i][j] != 0);
    }

    public static boolean solveRec(int maze[][], int i, int j, int N, int sol[][]) {
        if (i == N - 1 && j == N - 1) {
            sol[i][j] = 1;
            return true;
        }

        if (isSafe(maze, i, j, N) == true) {
            sol[i][j] = 1;

            for (int k = 1; k <= maze[i][j]; k++) {
                if (solveRec(maze, i, j + k, N, sol) == true)
                    return true;

                if (solveRec(maze, i + k, j, N, sol) == true)
                    return true;
            }

            sol[i][j] = 0;

        }

        return false;
    }

    public static void solve(int[][] maze, int N) {
        // add your code here
        int sol[][] = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sol[i][j] = 0;
            }
        }

        if (solveRec(maze, 0, 0, N, sol) == true) {
            printSolution(sol, N);
        } else
            System.out.println(-1);
    }
}
