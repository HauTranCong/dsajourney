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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right)
            return head;

        ListNode newHead(0, head);
        ListNode* prev = &newHead;

        for(int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        cout << prev->val;
        ListNode* tail = prev->next;
        // cout << tail->val;
        for(int i = 0; i < right - left; ++i) {
            ListNode* cur = tail->next; 
            tail->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }

        return newHead.next;
    }
};