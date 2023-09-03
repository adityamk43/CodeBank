/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 21
 * @author ADITYA BHARDWAJ
 * 20/08/2023 12:44 AM
 * 
 * @description
 * 11. Container With Most Water
    Medium
    26.1K
    1.4K
    Companies
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.

    

    Example 1:


    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
    Example 2:

    Input: height = [1,1]
    Output: 1
    

    Constraints:

    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104
    Accepted
    2.3M
    Submissions
    4.2M
    Acceptance Rate
    54.1%

 * @returns
    
    Accepted

    Runtime
    Details
    65ms
    Beats 91.35%of users with TypeScript
    Memory
    Details
    50.68MB
    Beats 95.67%of users with TypeScript
 */

function maxArea(height: number[]): number {
  let i = 0,
    j = height.length - 1;

  let area: number = 0;
  while (i < j) {
    area = Math.max(area, (j - i) * Math.min(height[i], height[j]));

    if (height[i] === height[j]) {
      i++;
      j--;
    } else if (height[i] < height[j]) i++;
    else j--;
  }

  return area;
}

//Test Cases

//Case 1
let height:number[]=[1,8,6,2,5,4,8,3,7];

//Case 2
// let height:number[]=[1,1];

//Case 3
// let height:number[]=[3,2,3];

//Case 4
// let height:number[]=[5, 0, 6, 2, 3];

//Case 5
// let height:number[]=[3, 0, 1, 2, 5];

//Case 6
// let height:number[]=[1,8,6,2,5,6,8,3,7];

console.log(maxArea(height));
