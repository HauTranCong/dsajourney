/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode *prev = nullptr, *next = nullptr;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

/*
    1. The next pointer works like a temporary to not affect on current pointer to iterate
    2. The cur->next points to previous ptr (the reverse happens in this step)
    3. Assign the previous to current to get value
    4. Update the current pointer equal to next pointer for the next iteration
*/