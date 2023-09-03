/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 31
 * @author ADITYA BHARDWAJ
 * 30/08/2023 01:19PM-02:10PM
 * 
 * @description
 * 875. Koko Eating Bananas
    Medium
    8.9K
    431
    Companies
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.

    

    Example 1:

    Input: piles = [3,6,7,11], h = 8
    Output: 4
    Example 2:

    Input: piles = [30,11,23,4,20], h = 5
    Output: 30
    Example 3:

    Input: piles = [30,11,23,4,20], h = 6
    Output: 23
    

    Constraints:

    1 <= piles.length <= 104
    piles.length <= h <= 109
    1 <= piles[i] <= 109
    Accepted
    435.5K
    Submissions
    867.8K
    Acceptance Rate
    50.2%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    68ms
    Beats 86.67%of users with TypeScript

    Memory
    Details
    45.95MB
    Beats 72.82%of users with TypeScript
 * 
 * 
 */

//Using Binary Search approach as Linear method causes TLE
function minEatingSpeed(piles: number[], h: number): number {
  let start: number = 1;
  let end: number = Math.max(...piles);
  let res: number = end;

  while (start <= end) {
    let mid: number = start + Math.floor((end - start) / 2);
    let count: number = 0;

    for (let pile of piles) count += Math.ceil(pile / mid);

    if (count <= h) {
      res = Math.min(res, mid);
      end = mid - 1;
    } else start = mid + 1;
  }

  return res;
}

//Test Cases

//Case 1
let piles:number[] = [3,6,7,11];
let h:number=8;

//Case 2
// let piles:number[] = [30,11,23,4,20];
// let h:number=5;

//Case 3
// let piles:number[] = [30,11,23,4,20];
// let h:number=6;

//Case 4
// let piles:number[] = [312884470];
// let h:number=312884469;

console.log(minEatingSpeed(piles, h));