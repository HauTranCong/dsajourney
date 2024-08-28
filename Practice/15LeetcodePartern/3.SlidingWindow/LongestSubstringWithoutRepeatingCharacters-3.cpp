class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> pos(128, -1);
        for(int i = 0, j = 0; j < s.size(); ++j) {
            if(pos[s[j]] != -1)
                i = max(i, pos[s[j]] + 1);
            ans = max(ans, j - i + 1);
            pos[s[j]] = j;
        }
        return ans;
    }
};