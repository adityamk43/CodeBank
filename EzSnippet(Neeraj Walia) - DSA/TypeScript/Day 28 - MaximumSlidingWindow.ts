/**
 *  
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 28
 * @author ADITYA BHARDWAJ
 * 27/08/2023 02:38 AM - 27/08/2023 10:15 AM
 * 
 * @description
 * 239. Sliding Window Maximum
    Hard
    16.8K
    567
    Companies
    You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

    Return the max sliding window.

    

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    

    Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length
    Accepted
    876.6K
    Submissions
    1.9M
    Acceptance Rate
    46.6%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    209ms
    Beats 100%of users with TypeScript

    Memory
    Details
    71.14MB
    Beats 92.64%of users with TypeScript
 */

    // class MaxHeap {
//     heap: { value: number; index: number }[];

//     constructor() {
//         this.heap = [];
//     }

//     private swap(index1: number, index2: number): void {
//         [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
//     }

//     private heapify(index: number): void {
//         const leftChildIndex = 2 * index + 1;
//         const rightChildIndex = 2 * index + 2;
//         let largestIndex = index;

//         if (leftChildIndex < this.heap.length && this.heap[leftChildIndex].value > this.heap[largestIndex].value) {
//             largestIndex = leftChildIndex;
//         }
//         if (rightChildIndex < this.heap.length && this.heap[rightChildIndex].value > this.heap[largestIndex].value) {
//             largestIndex = rightChildIndex;
//         }

//         if (largestIndex !== index) {
//             this.swap(index, largestIndex);
//             this.heapify(largestIndex);
//         }
//     }

//     insert(value: number, index: number): void {
//         this.heap.push({ value, index });

//         let currentIndex = this.heap.length - 1;
//         let parentIndex = Math.floor((currentIndex - 1) / 2);

//         while (currentIndex > 0 && this.heap[currentIndex].value > this.heap[parentIndex].value) {
//             this.swap(currentIndex, parentIndex);
//             currentIndex = parentIndex;
//             parentIndex = Math.floor((currentIndex - 1) / 2);
//         }
//     }

//     pop(): { value: number; index: number } | undefined {
//         if (this.heap.length === 0) {
//             return undefined;
//         }

//         if (this.heap.length === 1) {
//             return this.heap.pop();
//         }

//         const max = this.heap[0];
//         this.heap[0] = this.heap.pop()!;

//         this.heapify(0);

//         return max;
//     }

//     peekMax(): { value: number; index: number } | undefined {
//         return this.heap[0];
//     }
// }

// function maxSlidingWindow(nums: number[], k: number): number[] {
//     const result: number[] = [];
//     const maxHeap = new MaxHeap();

//     for (let i = 0; i < k; i++) {
//         maxHeap.insert(nums[i], i);
//     }
//         // console.log(maxHeap);
//         // console.log(maxHeap.peekMax()!.index)

//     for (let i = k; i < nums.length; i++) {
//         result.push(maxHeap.peekMax()!.value);

//         // console.log(maxHeap);
//         // console.log(maxHeap.peekMax()!.index)

//         while (maxHeap.peekMax()?.index <= i - k) {
//             maxHeap.pop();
//         }

//         maxHeap.insert(nums[i], i);
//     }

//     result.push(maxHeap.peekMax()!.value);

//     return result;
// }


//Using Dequeue to optimise my runtime and memory  than others
function maxSlidingWindow(nums: number[], k: number): number[] {
    const result: number[] = [];
    const deque: number[] = []; // Maintain indices in the deque

    for (let i = 0; i < nums.length; i++) {
        // Remove indices that are out of the window
        while (deque.length > 0 && deque[0] <= i - k) {
            deque.shift();
        }

        // Remove indices of smaller elements as they are no longer candidates for maximum
        while (deque.length > 0 && nums[i] >= nums[deque[deque.length - 1]]) {
            deque.pop();
        }

        // Add the current index to the deque
        deque.push(i);

        // Add the maximum element for the current window to the result
        if (i >= k - 1) {
            result.push(nums[deque[0]]);
        }
    }

    return result;
}

//Test Cases

//Case 1
let nums:number[] = [1,3,-1,-3,5,3,6,7];
let k:number=3;

//Case 2
// let nums:number[] = [1];
// let k:number=1;

//Case 1
// let nums:number[] = [1,-1];
// let k:number=3;

console.log(maxSlidingWindow(nums, k));