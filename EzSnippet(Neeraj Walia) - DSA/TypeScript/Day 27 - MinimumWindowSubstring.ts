/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 27
 * @author ADITYA BHARDWAJ
 * 27/08/2023 01:13 AM (Got late due to freshers aarambh 2k23 function)
 * 
 * @description
 * 76. Minimum Window Substring
    Hard
    16K
    657
    Companies
    Given two strings s and t of lengths m and n respectively, return the minimum window 
    substring
    of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.

    

    Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    Example 2:

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.
    Example 3:

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
    

    Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
    

    Follow up: Could you find an algorithm that runs in O(m + n) time?
  
    @returns
    Accepted

    Runtime
    Details
    67ms
    Beats 99.56%of users with TypeScript

    Memory
    Details
    44.82MB
    Beats 100.00%of users with TypeScript
 */

// function minWindow(s: string, t: string): string {

//     if (t.length > s.length)
//         return "";

//     let sMap = new Map();
//     let tMap = new Map();
//     let sCount: number = 0;
//     let tCount: number = 0;
//     let res: string = "";
//     let subStr: string = "";

//     for (let i = 0; i < t.length; i++) {
//         tMap.set(t[i], tMap.has(t[i]) ? tMap.get(t[i]) + 1 : 1);
//         tCount++;
//     }

//     // console.log(tMap, tCount);

//     let start: number = 0;
//     for (let i = 0; i < s.length; i++) {

//         // console.log("--------")
//         // console.log("LOOP NO: ", i + 1);

//         sMap.set(s[i], sMap.has(s[i]) ? sMap.get(s[i]) + 1 : 1);
//         // console.log("SMap first: ", sMap)
//         subStr += s[i];
//         // console.log("Substr first", subStr);

//         if (tMap.has(s[i]) && sMap.get(s[i]) <= tMap.get(s[i]))
//             sCount++;
//         else if (sCount > 0 && tMap.has(s[i]) && sMap.get(s[i]) < tMap.get(s[i]))
//             sCount--;

//         // console.log("sCount first: ", sCount);
//         while (sCount === tCount) {
//             if (res === "" || subStr.length <= res.length) {
//                 res = subStr;
//             }

//             // console.log(sMap.has(s[start]) && sMap.get(s[start]) > 1)
//             if (tMap.has(s[start]) && tMap.get(s[start]) > sMap.get(s[start]) - 1)
//                 sCount--;

//             if (sMap.get(s[start]) > 1) {
//                     sMap.set(s[start], sMap.get(s[start]) - 1);
//                 }
//                 else
//                     sMap.delete(s[start]);

//             subStr = subStr.slice(1);
//             start++;

//         }

//         // console.log(subStr);
//         // console.log(sCount);
//         // console.log(sMap);
//         // console.log("start ", start);
//         // console.log("res ", res);
//         // console.log("-----")
//     }

//     return res;
// };

// Optimised my code a little bit to make runtime and memory better than others by using array instead of map as we are only using ascii characters in map and instead of using temp var as subStr we just use index to set substr of main string s to store that particular substring using start and i index value to answer variabl res.
function minWindow(s: string, t: string): string {
  if (t.length > s.length) {
    return "";
  }

  const sFreq = new Array(128).fill(0); // Assuming ASCII characters
  const tFreq = new Array(128).fill(0);
  let sCount = 0;
  let tCount = 0;
  let res = "";
  let start = 0;

  for (let i = 0; i < t.length; i++) {
    tFreq[t.charCodeAt(i)]++;
    tCount++;
  }

  for (let i = 0; i < s.length; i++) {
    const charCode = s.charCodeAt(i);
    sFreq[charCode]++;

    if (tFreq[charCode] > 0 && sFreq[charCode] <= tFreq[charCode]) {
      sCount++;
    } else if (
      sCount > 0 &&
      tFreq[charCode] > 0 &&
      sFreq[charCode] < tFreq[charCode]
    ) {
      sCount--;
    }

    while (sCount === tCount) {
      const currentLength = i - start + 1;
      if (res === "" || currentLength < res.length) {
        res = s.substring(start, i + 1);
      }

      const startCharCode = s.charCodeAt(start);
      if (
        tFreq[startCharCode] > 0 &&
        tFreq[startCharCode] >= sFreq[startCharCode]
      ) {
        sCount--;
      }

      sFreq[startCharCode]--;
      start++;
    }
  }

  return res;
}


//Test Cases

//Case 1
let s:string="ADOBECODEBANC";
let t:string="ABC";

//Case 2
// let s:string="a";
// let t:string="a";

//Case 3
// let s:string="a";
// let t:string="aa";

//Case 4
// let s:string="aa";
// let t:string="aa";

console.log(minWindow(s, t));

