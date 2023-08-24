/**
 * @event DailyStreak(2)
 * @author ADITYA BHARDWAJ
 * @date 14 August 2023, 02:33 PM
 * @description
 * 
 * 68. Text Justification
    Hard
    2.7K
    3.8K
    Companies
    Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

    Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

    For the last line of text, it should be left-justified, and no extra space is inserted between words.

    Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.
    

    Example 1:

    Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
    Output:
    [
    "This    is    an",
    "example  of text",
    "justification.  "
    ]
    Example 2:

    Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
    Output:
    [
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
    ]
    Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
    Note that the second line is also left-justified because it contains only one word.
    Example 3:

    Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
    Output:
    [
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
    ]
    

    Constraints:

    1 <= words.length <= 300
    1 <= words[i].length <= 20
    words[i] consists of only English letters and symbols.
    1 <= maxWidth <= 100
    words[i].length <= maxWidth
    Accepted
    321.7K
    Submissions
    818.8K
    Acceptance Rate
    39.3%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    45ms
    Beats 99.34%of users with TypeScript

    Memory
    Details
    43.08MB
    Beats 73.03%of users with TypeScript
 *
 */

function fullJustify(words: string[], maxWidth: number): string[] {
  //declaring a string array to maintain each line words
  let curr: string[] = [];
  //declaring a variable to store the number of letters for each line
  let num_of_letters: number = 0;
  //Final string array that is to be maintained during the loop and returned at last as an answer
  let res: string[] = [];

  //Traversing the given string array word and applying the logic
  for (let word of words) {
    //if current word plus total words plus total letters of those words exceed the given maxWidth then we need to push this curr array along with justified even spaces between those words
    if (word.length + curr.length + num_of_letters > maxWidth) {
      // we run another loop inside this until while filling spaces the total length of this line equals maxWidth
      //we give priority to left space justification first as given in this question
      for (let i: number = 0; i < maxWidth - num_of_letters; i++) {
        curr[i % (curr.length - 1 || 1)] += " ";
      }

      //atlast we push the curr array concated to the res string array and reset the curr and num_of_letters for the new line.
      res.push(curr.join(""));
      curr = [];
      num_of_letters = 0;
    }

    /**NOTE: Remember when the if condition is entered above the curr and num_of_letters gets reset for the new line */
    //pushing the word from words string array along the traversal to maintain each line word record
    curr.push(word);
    //maintaining each line num_of_letters by adding length of the word along the traversal
    num_of_letters += word.length;
  }

  // In the last since as given in question last line should be left justified, we add spaces to the right of the concated curr array (if length not zero) accordingly to match the maxWidth.
  let lastLine: string = curr.join(" ");

  while (lastLine.length < maxWidth) lastLine += " ";

  //Finally we push the lastLine and return the final answer
  res.push(lastLine);

  return res;
}

//Test Cases

//Case 1
// let words:string[]=["This", "is", "an", "example", "of", "text", "justification."];
// let maxWidth:number=16;

//Case 2
// let words:string[]=["What","must","be","acknowledgment","shall","be"];
// let maxWidth:number=16;

//Case 3
let words:string[]=["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"];
let maxWidth:number=20;

console.log(fullJustify(words, maxWidth));
