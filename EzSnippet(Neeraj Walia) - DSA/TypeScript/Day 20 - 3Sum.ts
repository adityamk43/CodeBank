/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 20
 * @author ADITYA BHARDWAJ
 * 19/08/2023 1:44 AM - few test cases failed
 * 19/08/2023 12:15 PM - PAssed all test cases with flying colors :)
 * 
 * @description
 * 15. 3Sum
    Medium
    27.8K
    2.5K
    Companies
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
    Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.
    

    Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
    Accepted
    2.9M
    Submissions
    8.6M
    Acceptance Rate
    33.1%

    @returns
    Accepted

    Runtime
    Details
    149ms
    Beats 93.70%of users with TypeScript

    Memory
    Details
    58.74MB
    Beats 85.16%of users with TypeScript
 */