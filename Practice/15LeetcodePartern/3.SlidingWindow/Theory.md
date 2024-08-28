# Sliding Window
The Sliding Window parttern is used to find a subarray or substring that sastifies a
specific condition, optimizing the time complexity by maintaining a window of elements

Use this pattern when dealing with problems involving contiguous subarrays or substrings.

## Sample Problem:
Find the maximum sum of a subarray of size k.

## Example:
Input: nums = [2, 1, 5, 1, 3, 2], k = 3
Output: 9

## Explanation:
1. Start with the sum of the first k elements.
2. Slide the window one element at a time, subtracting the element that goes out of the window
and adding the new element.
3. Keep track of the maximum sum encountered.

## LeetCode Problems:
1. Maximum Average Subarray I (LeetCode #643)
2. Longest Substring Without Repeating Characters (LeetCode #3)
3. Minimum Window Substring (LeetCode #76)

