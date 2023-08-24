### Dry Run to easily understand logic of Text Justification Problem (Streak 2 Problem 24-Aug-2023)

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

1. This

   word.length=4

   cur.length=0

   num_of_letters=0

   0+4+0>16 False

cur=["This"]

num_of_letters+=word.length(4)

num_of_letters=4

2. is

   word.length=2

   curr.length=1

   num_of_letters=4

   2+1+4=7>16 False

cur=["This", "is"]

num_of_letters+=word.length(2)

num_of_letters=6

3. an

   word.length=2

   curr.length=2

   num_of_letters=6

   2+2+6=10>16 False

cur=["This", "is", "an"]

num_of_letters+=word.length(2)

num_of_letters=8

4. example

   word.length=7

   curr.length=3

   num_of_letters=8

   7+3+8=18>16 True

> Inside Loop =>

```
 1. i=0
 maxWidth(16) - num_of_letters(8) =8
 0<8 T
 cur[0%(3-1)]+=""
 cur=["This ", "is", "an"]

 2. i=1
 maxWidth(16) - num_of_letters(8) =8
 1<8 T
 cur[1%(3-1)]+=""
 cur=["This ", "is ", "an"]

 3. i=2
 maxWidth(16) - num_of_letters(8) =8
 2<8 T
 cur[2%(3-1)]+=""
 cur=["This ", "is ", "an"]

 4. i=3
 maxWidth(16) - num_of_letters(8) =8
 3<8 T
 cur[3%(3-1)]+=""
 cur=["This ", "is ", "an"]

 5. i=4
 maxWidth(16) - num_of_letters(8) =8
 4<8 T
 cur[4%(3-1)]+=""
 cur=["This ", "is ", "an"]

 6. i=5
 maxWidth(16) - num_of_letters(8) =8
 5<8 T
 cur[4%(3-1)]+=""
 cur=["This ", "is ", "an"]

 7. i=6
 maxWidth(16) - num_of_letters(8) =8
 6<8 T
 cur[6%(3-1)]+=""
 cur=["This ", "is ", "an"]

 8. i=7
 maxWidth(16) - num_of_letters(8) =8
 7<8 T
 cur[7%(3-1)]+=""
 cur=["This ", "is ", "an"]
```

res = ["This is an"]

cur=[]

num_of_letters=0

cur=["example"]

num_of_letters+=word.length(7)

num_of_letters=7

##### Code for reference

```ts
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
```
