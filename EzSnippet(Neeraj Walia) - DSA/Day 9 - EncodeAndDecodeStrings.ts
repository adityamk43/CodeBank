/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 9
 * 07/08/2023 11:01:20 PM
 * @description Design an algorithm to encode a list of strings to a string. The encoded string is sent over the network and is decoded back to the original list of strings.
 *
 * Please implement encode and decode.
 *
 * Example:
 *
 * Input: ["lint", "code", "love", "you"]
 * Output: ["lint", "code", "love", "you"]
 *
 * Explanation:
 * One possible encode method is: "lint:;code:;love:;you"
 */
let encoder: string = ":;";

const encode = (s1: string[]): string => {
  let temp: string = "";

  for (let i: number = 0; i < s1.length; i++) {
    temp += s1[i];
    if (i + 1 !== s1.length) {
      temp += encoder;
    }
  }

  // Simplest way by using inbuilt js/ts function of joining strings to encode
  // temp=s1.join(":;")

  return temp;
};

// const decode = (encodedString: string): string[] => {
//   let decodedString: string[] = [];

//   let temp: string = "";
//   for (let i: number = 0; i < encodedString.length; i++) {
//     if (encodedString[i] === encoder[0]) {
//       decodedString.push(temp);
//       temp = "";
//       i++;
//     } else {
//       temp += encodedString[i];
//     }
//   }

//   decodedString.push(temp);
//   // Simplest way by using inbuilt js/ts function of splitting string list to decode
//   //   temp = encodedString.split(encoder);

//   return decodedString;
// };

// My optimised decode function as per chatGPT suggestions
/**
 * @summary
 * Your code appears to be a reasonable implementation of encoding and decoding a list of strings. It follows the specified algorithm and seems to work as intended. Here are some thoughts and suggestions on your code:

Variable Naming and Clarity: Your variable names are mostly clear and descriptive, making the code relatively easy to understand. However, you could consider using more descriptive names for variables like temp, which could be named something like currentSegment or currentString.

Simplification: You've mentioned the simplest ways to achieve the encoding and decoding using built-in JavaScript/TypeScript functions (join and split). Utilizing these functions can simplify your code and reduce the chance of errors. Using the built-in functions can also improve the performance of your code, especially for larger inputs.

Edge Case Handling: Your current implementation handles most cases well, but you should consider adding additional tests for edge cases to ensure your code handles all scenarios correctly. For instance, try testing with empty strings, strings containing the encoder characters, and very large input strings.

Comments and Documentation: You've provided comments explaining the purpose of each function and the overall algorithm, which is great for understanding. Consider adding more detailed comments for complex parts of the code, especially if you choose to optimize it further.

Performance: While your current implementation is correct, the for loop in your decode function might be less efficient for very large strings, as you are repeatedly appending characters to the temp string. Using an array to build the temp string and then joining it at the end could potentially improve performance.

Here's an updated version of your decode function that uses an array to build the temp string and then joins it at the end:
 */

const decode = (encodedString: string): string[] => {
  let decodedString: string[] = [];
  let temp: string[] = [];

  for (let i = 0; i < encodedString.length; i++) {
    if (encodedString[i] === encoder[0]) {
      decodedString.push(temp.join(""));
      temp = [];
      i++;
    } else {
      temp.push(encodedString[i]);
    }
  }

  decodedString.push(temp.join(""));

  return decodedString;
};

let s1: string[] = ["lint", "code", "love", "you"];
console.log(s1);

let encodedString: string = encode(s1);
console.log(encodedString);

let decodedString: string[] = decode(encodedString);
console.log(decodedString);

// CUSTOM SPLIT PRACTICE
console.log(s1.indexOf("lint", 2));

/** 
function customSplit(str, separator) {
    const result = [];
    let startIndex = 0;
    let nextIndex;

    while ((nextIndex = str.indexOf(separator, startIndex)) !== -1) {
        result.push(str.substring(startIndex, nextIndex));
        startIndex = nextIndex + separator.length;
    }

    if (startIndex < str.length) {
        result.push(str.substring(startIndex));
    }

    return result;
}
 */
