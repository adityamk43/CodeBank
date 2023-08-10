/***
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 12
 * @author ADITYA BHARDWAJ
 * 11/08/2023 12:32 AM
 * @description
 * 155. Min Stack
    Medium
    12.5K
    765
    Companies
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

    

    Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    

    Constraints:

    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.
    Accepted
    1.4M
    Submissions
    2.6M
    Acceptance Rate
    52.8%
 */

/**
 * MY IMPLEMENTATION
 * @description
 *  Runtime
    Details
    91ms
    Beats 94.50%of users with TypeScript

    Memory
    Details
    51.67mb
    Beats 52.93%of users with TypeScript
 */
// class MinStack {
//   private stack: number[];
//   private minStack: number[];

//   constructor() {
//     this.stack = [];
//     this.minStack = [];
//   }

//   push(val: number): void {
//     this.stack.push(val);

//     if (this.minStack.length !== 0)
//       this.minStack.push(
//         Math.min(val, this.minStack[this.minStack.length - 1])
//       );
//     else this.minStack.push(val);
//   }

//   pop(): void {
//     if (this.stack.length !== 0) {
//       this.stack.pop();
//     }
//     if (this.minStack.length !== 0) {
//       this.minStack.pop();
//     }
//   }

//   top(): number {
//     return this.stack[this.stack.length - 1];
//   }

//   getMin(): number {
//     return this.minStack[this.minStack.length - 1];
//   }
// }

/**
 * @description Another efficient implementation using only this stack having element as objects with two properties:- value pushed and minimum value
 * 
 *  Runtime
    Details
    93ms
    Beats 92.59%of users with TypeScript

    Memory
    Details
    50.78mb
    Beats 90.68%of users with TypeScript


 *  NOTE: There is not much difference between my implementation and this implementation both are same in speed but have different approaches!! and both are best according to me!
 */
class MinStack {
  private stack: { value: number; minVal: number }[];

  constructor() {
    this.stack = [];
  }

  push(val: number): void {
    this.stack.push({
      value: val,
      minVal:
        this.stack.length === 0
          ? val
          : Math.min(val, this.stack[this.stack.length - 1].minVal),
    });
  }

  pop(): void {
    this.stack.pop();
  }

  top(): number {
    return this.stack[this.stack.length - 1].value;
  }

  getMin(): number {
    return this.stack[this.stack.length - 1].minVal;
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

/**
 * I/P:
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 */
let val: number;

// 1. MinStack
var obj = new MinStack();

// 2. push
val = -2;
obj.push(val);

// 3. push
val = 0;
obj.push(val);

// 4. push
val = -3;
obj.push(val);

// 5. getMin
console.log(obj.getMin()); //return -3

// 6. pop
obj.pop();

// 7. top
var param_3 = obj.top(); //return 0
console.log(param_3);

// 8. getMin
var param_4 = obj.getMin(); //return -2
console.log(param_4);
