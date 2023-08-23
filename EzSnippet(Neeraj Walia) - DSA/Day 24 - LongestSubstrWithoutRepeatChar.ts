/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 24
 * @author ADITYA BHARDWAJ
 * 23/08/2023 11:14 AM
 * 
 * @description
    * 3. Longest Substring Without Repeating Characters
    Medium
    36.5K
    1.6K
    Companies
    Given a string s, find the length of the longest 
    substring
    without repeating characters.

    

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    

    Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
    Accepted
    4.8M
    Submissions
    14.2M
    Acceptance Rate
    33.9%
 * @returns
 * Accepted

    Runtime
    Details
    68ms
    Beats 92.78%of users with TypeScript

    Memory
    Details
    44.64MB
    Beats 97.77%of users with TypeScript
 */

function lengthOfLongestSubstring(s: string): number {
  let hashMap = new Map();
  let start = 0;
  let maxLength = 0;

  for (let end = 0; end < s.length; end++) {
    let char = s.charAt(end);

    if (hashMap.has(char) && hashMap.get(char) >= start) {
      start = hashMap.get(char) + 1;
    }

    hashMap.set(char, end);
    maxLength = Math.max(maxLength, end - start + 1);
    // console.log(start);
    // console.log(maxLength);
    // console.log(hashMap);
  }

  return maxLength;
}

//Test Cases

//Case 1
let s:string="abcabcbb";

//Case 2
// let s:string="bbbbb";

//Case 3
// let s:string="pwwkew";

//Case 4
// let s:string="abba";

console.log(lengthOfLongestSubstring(s));