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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<vector<bool> > seen(m, vector<bool>(n, false));
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        int row = 0, col = 0;
        int di = 0;
        
        while(head) {
            matrix[row][col] = head->val;
            seen[row][col] = true;
            int newRow = row + dr[di];
            int newCol = col + dc[di];
            if(0 <= newCol && newCol < n && 0 <= newRow && newRow < m && !seen[newRow][newCol]) {
                row = newRow;
                col = newCol;
            } else {
                di = (di + 1) % 4;
                row += dr[di];
                col += dc[di];
            }
            head = head->next;
        }

        return matrix;
    }
};