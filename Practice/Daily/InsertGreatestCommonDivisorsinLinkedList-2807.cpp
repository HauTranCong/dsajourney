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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur->next) {
            int minVal = min(cur->val, cur->next->val);
            int maxVal = 0;
            for(int i = 1; i <= minVal; i++) {
                if((cur->val % i) == 0 && (cur->next->val % i) == 0)
                    maxVal = max(maxVal, i);
            }
            ListNode* addNode = new ListNode(maxVal, cur->next);
            cur->next = addNode;
            cur = addNode->next;
        }
        return head;
    }
};