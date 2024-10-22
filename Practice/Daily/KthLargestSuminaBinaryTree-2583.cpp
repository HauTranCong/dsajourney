/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = -1;
        unordered_map<int,long long> mp;
        priority_queue<long long> pq;
        bfs(root, mp);
        for(const auto& idx : mp)
            pq.push(idx.second);
        while(!pq.empty() && k) {
            k -= 1;
            if(k == 0)
                ans = pq.top();
            pq.pop();
        }
        return ans;
    }
    void bfs(TreeNode* root, unordered_map<int,long long>& mp) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            pair<TreeNode*, int> node = q.front();
            mp[node.second] += node.first->val;
            q.pop();
            if(node.first->left != nullptr)
                q.push({node.first->left, node.second + 1});
            if(node.first->right != nullptr)
                q.push({node.first->right, node.second + 1});
        }
    }
};