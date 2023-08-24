/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 25
 * @author ADITYA BHARDWAJ
 * 24/08/2023 01:12 PM
 * 
 * @description
 * 424. Longest Repeating Character Replacement
    Medium
    9.2K
    386
    Companies
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achive this answer too.
    

    Constraints:

    1 <= s.length <= 105
    s consists of only uppercase English letters.
    0 <= k <= s.length
    Accepted
    524K
    Submissions
    999K
    Acceptance Rate
    52.5%

 * @returns
 * Accepted

    Runtime
    Details
    85ms
    Beats 60.76%of users with TypeScript

    Memory
    Details
    44.37MB
    Beats 73.57%of users with TypeScript
 */

function characterReplacement(s: string, k: number): number {
  let start: number = 0;
  let freqMap = new Map();
  let maxFreq: number = 0;
  let maxLength: number = 0;

  for (let end: number = 0; end < s.length; end++) {
    freqMap.has(s[end])
      ? freqMap.set(s[end], freqMap.get(s[end]) + 1)
      : freqMap.set(s[end], 1);

    maxFreq = Math.max(maxFreq, freqMap.get(s[end]));

    while (end - start + 1 - maxFreq > k) {
      freqMap.set(s[start], freqMap.get(s[start]) - 1);
      start++;
    }
    maxLength = Math.max(maxLength, end - start + 1);
    // console.log(freqMap);
    // console.log(maxFreq);
    // console.log(start);
    // console.log(end);
    // console.log(maxLength);
  }

  return maxLength;
}

//Test Cases

//Case 1
let s:string="ABAB";
let k:number=2;

//Case 2
// let s:string="AABABBA";
// let k:number=1;

console.log(characterReplacement(s, k));