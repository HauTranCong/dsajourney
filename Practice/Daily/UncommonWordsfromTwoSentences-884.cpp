class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string tmp; 
        unordered_map<string, int> mp;
        vector<string> ans;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] == ' ') {
                mp[tmp]++;
                tmp = "";
            }
            else {
                tmp += s1[i];
            }
        }
        mp[tmp]++;
        tmp = "";
        for(int i = 0; i < s2.length(); ++i) {
            if(s2[i] == ' ') {
                mp[tmp]++;
                tmp = "";
            }
            else {
                tmp += s2[i];
            }
        }
        mp[tmp]++;

        for(const auto& idx : mp) {
            if(idx.second == 1) {
                ans.push_back(idx.first);
            }
        }

        return ans;
    }
};