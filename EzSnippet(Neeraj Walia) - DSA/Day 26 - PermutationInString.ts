/**
 *
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 26
 * @author ADITYA BHARDWAJ
 * 25/08/2023 12:49 PM
 * 
 * @description (Visit: https://leetcode.com/problems/permutation-in-string/editorial/ for more clear understanding of the algorithm)
 * 567. Permutation in String
    Medium
    10.5K
    341
    Companies
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    

    Example 1:

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
    Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
    

    Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
    Accepted
    0
    Submissions
    0
    Acceptance Rate
    0%

 * @returns
 * Accepted

    Runtime
    Details
    60ms
    Beats 98.52%of users with TypeScript

    Memory
    Details
    44.58MB
    Beats 92.33%of users with TypeScript

 * @returns (For Using count variable tracking)
   Accepted

    Runtime
    Details
    62ms
    Beats 97.34%of users with TypeScript

    Memory
    Details
    44.18MB
    Beats 97.64%of users with TypeScript
 */

// My Approach - Hashmap : slow
// function matchMap(s1Map, s2Map): boolean {
//     for (const [key, value] of s1Map) {
//         // console.log(key);
//         // console.log(s2Map.has(key));
//         // console.log(value - s2Map.get(key));

//         if (!s2Map.has(key))
//             return false;
//         else if (value - s2Map.get(key) != 0)
//             return false;
//     };
//     return true;
// }

// function checkInclusion(s1: string, s2: string): boolean {

//     if (s1.length > s2.length)
//         return false;

//     let s1Map = new Map();

//     for (let i = 0; i < s1.length; i++) {
//         s1Map.set(s1[i], s1Map.has(s1[i]) ? s1Map.get(s1[i]) + 1 : 1);
//     }

//     // console.log(s1Map);

//     for (let i = 0; i <= s2.length - s1.length; i++) {
//         let s2Map = new Map();

//         for (let j = 0; j < s1.length; j++) {
//             s2Map.set(s2[i + j], s2Map.has(s2[i + j]) ? s2Map.get(s2[i + j]) + 1 : 1);
//         }

//         // console.log(s1Map);
//         // console.log(s2Map);
//         if (matchMap(s1Map, s2Map))
//             return true;
//     }

//     return false;
// };

// function matchMap(s1Map, s2Map): boolean {
//     for (const [key, value] of s1Map) {
//         // console.log(key);
//         // console.log(s2Map.has(key));
//         // console.log(value - s2Map.get(key));

//         if (!s2Map.has(key))
//             return false;
//         else if (value - s2Map.get(key) != 0)
//             return false;
//     };
//     return true;
// }

// My Approach modified from HashMap to 26 length of Array but still slow
// function matchMap(s1Map:number[], s2Map:number[]): boolean {
//     for (let i = 0; i < 26; i++) {

//         if (s1Map[i] != s2Map[i])
//             return false;
//     };
//     return true;
// }

// function checkInclusion(s1: string, s2: string): boolean {

//     if (s1.length > s2.length)
//         return false;

//     let s1Map:number[] = new Array(26).fill(0);

//     for (let i = 0; i < s1.length; i++) {
//         s1Map[s1.charCodeAt(i) - 97]++;
//     }

//     // console.log(s1Map);

//     for (let i = 0; i <= s2.length - s1.length; i++) {
//         let s2Map:number[] = new Array(26).fill(0);

//         for (let j = 0; j < s1.length; j++) {
//             s2Map[s2.charCodeAt(i+j) - 97]++;
//         }

//         // console.log(s1Map);
//         // console.log(s2Map);
//         if (matchMap(s1Map, s2Map))
//             return true;
//     }

//     return false;
// };

// Modified my approach a little bit more to save time and space complexity by preventing declaring s2Map again and again for every loop and using sliding window approach to declare s2Map 1 time and then moving the sliding moving in a way to decrement the freq of char of character that is moved out of the sliding window and adding the freq of the character that has moved into the sliding window.
// NOTE: Sliding window is moving from left to right
// function matchMap(s1Map: number[], s2Map: number[]): boolean {
//     for (let i = 0; i < 26; i++) {

//         if (s1Map[i] != s2Map[i])
//             return false;
//     };
//     return true;
// }

// function checkInclusion(s1: string, s2: string): boolean {

//     if (s1.length > s2.length)
//         return false;

//     let s1Map: number[] = new Array(26).fill(0);
//     let s2Map: number[] = new Array(26).fill(0);

//     for (let i = 0; i < s1.length; i++) {
//         s1Map[s1.charCodeAt(i) - 97]++;
//         s2Map[s2.charCodeAt(i) - 97]++;
//     }

//     // console.log(s1Map);

//     for (let i = 0; i <= s2.length - s1.length; i++) {

//         if (matchMap(s1Map, s2Map))
//             return true;

//         s2Map[s2.charCodeAt(i + s1.length) - 97]++;
//         s2Map[s2.charCodeAt(i) - 97]--;

//         // console.log(s1Map);
//         // console.log(s2Map);
//     }

//     return matchMap(s1Map, s2Map);
// };

/**
The last approach can be optimized, if instead of comparing all the elements of the hashmaps for every updated s2maps2maps2map corresponding to every window of s2s2s2 considered, we keep a track of the number of elements which were already matching in the earlier hashmap and update just the count of matching elements when we shift the window towards the right.

To do so, we maintain a countcountcount variable, which stores the number of characters(out of the 26 alphabets), which have the same frequency of occurence in s1s1s1 and the current window in s2s2s2. When we slide the window, if the deduction of the last element and the addition of the new element leads to a new frequency match of any of the characters, we increment the countcountcount by 1. If not, we keep the countcountcount intact. But, if a character whose frequency was the same earlier(prior to addition and removal) is added, it now leads to a frequency mismatch which is taken into account by decrementing the same countcountcount variable. If, after the shifting of the window, the countcountcount evaluates to 26, it means all the characters match in frequency totally. So, we return a True in that case immediately.
 */
function checkInclusion(s1: string, s2: string): boolean {
  if (s1.length > s2.length) return false;

  let s1Map: number[] = new Array(26).fill(0);
  let s2Map: number[] = new Array(26).fill(0);
  let count: number = 0;

  for (let i = 0; i < s1.length; i++) {
    s1Map[s1.charCodeAt(i) - 97]++;
    s2Map[s2.charCodeAt(i) - 97]++;
  }

  // console.log(s1Map);

  for (let i = 0; i < 26; i++) {
    if (s1Map[i] === s2Map[i]) count++;
  }

  for (let i = 0; i <= s2.length - s1.length; i++) {
    let l: number = s2.charCodeAt(i) - 97,
      r: number = s2.charCodeAt(i + s1.length) - 97;
    if (count === 26) return true;

    s2Map[r]++;

    if (s1Map[r] === s2Map[r]) count++;
    else if (s1Map[r] + 1 === s2Map[r]) count--;

    s2Map[l]--;
    if (s1Map[l] === s2Map[l]) count++;
    else if (s1Map[l] - 1 === s2Map[l]) count--;

    // console.log(s1Map);
    // console.log(s2Map);
  }

  return count === 26;
}

//Test Cases

//Case 1
// let s1: string = "ab";
// let s2: string = "eidbaooo";

//Case 2
// let s1:string="ab";
// let s2:string="eidboaoo";

//Case 3
let s1:string="adc";
let s2:string="dcda";

console.log(checkInclusion(s1, s2));
