# Fast & Slow Pointers
The Fast & Slow Pointers (Tortoise and Hare) pattern is used to detect cycles in linked lists and other similar structures.

## Sample Problem:
Detect if a linked list has a cycle.

## Explanation:
1. Initialize two pointers, one moving one step at a time (slow) and 
the other moving two steps at a time (fast).
2. If there is a cycle, the fast pointer will eventually meet the slow pointer.
3. If the fast pointer reaches the end of the list, there is no cycle.

## LeetCode Problems:
Linked List Cycle (LeetCode #141)
Happy Number (LeetCode #202)
Find the Duplicate Number (LeetCode #287)

