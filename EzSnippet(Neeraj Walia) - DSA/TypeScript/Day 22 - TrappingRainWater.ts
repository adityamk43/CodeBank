/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 22
 * @author ADITYA BHARDWAJ
 * 21/08/2023 11:50 AM
 * 
 * @description
 * 42. Trapping Rain Water
    Hard
    28.5K
    403
    Companies
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    

    Example 1:


    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
    Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9
    

    Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
    Accepted
    1.6M
    Submissions
    2.7M
    Acceptance Rate
    59.7%
 * @returns
 * Accepted

    Runtime
    Details
    56ms
    Beats 93.96%of users with TypeScript

    Memory
    Details
    44.84MB
    Beats 91.69%of users with TypeScript
 */

//using two pointer approach
/**
Time Complexity: O(n)
Space Complexity: O(1)
 */
function trap(height: number[]): number {
  let n = height.length;
  let lmax: number = height[0];
  let rmax: number = height[n - 1];

  let water: number = 0;

  let lpos: number = 1;
  let rpos: number = n - 2;

  while (lpos <= rpos) {
    // console.log("rpos ", rpos);
    // console.log("lpos ", lpos);
    // console.log("lmax ", lmax);
    // console.log("rmax ", rmax);
    // console.log("height[lpos] ", height[lpos]);
    // console.log("height[rpos] ", height[rpos]);
    // console.log("water ", water);
    if (height[lpos] >= lmax) {
      // console.log("height[lpos] >= lmax")
      lmax = height[lpos];
      lpos++;
    } else if (height[rpos] >= rmax) {
      // console.log("height[rpos] >= rmax")
      rmax = height[rpos];
      rpos--;
    } else if (lmax <= rmax && height[lpos] < lmax) {
      // console.log("lmax <= rmax && height[lpos] < lmax")
      water += lmax - height[lpos];
      lpos++;
    } else {
      // console.log("else part")
      water += rmax - height[rpos];
      rpos--;
    }
    // console.log();
  }

  return water;
}

// using two array lmax and rmax method
/**
Time Complexity: O(n)
Space Complexity: O(n)
 */
// function trap(height: number[]): number {

//     let n = height.length;
//     let water:number=0;

//     let lmax:number[]=new Array(n);
//     let rmax:number[]=new Array(n);

//     lmax[0]=height[0];
//     rmax[n-1]=height[n-1];

//     for (let i:number=1; i<n; i++)
//         lmax[i]=Math.max(lmax[i-1], height[i]);

//     for (let i:number=n-2; i>=0; i--)
//         rmax[i]=Math.max(rmax[i+1], height[i]);

//     for (let k:number=1; k<n-1; k++)
//         water+=Math.min(lmax[k], rmax[k])-height[k]

//     return water;

// };

//Test Cases

//Case 1
let height: number[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];

//Case 2
// let height:number[]=[4,2,0,3,2,5];

console.log(trap(height));
