class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mask = mask^(s[i] - 'a' + 1);
            }
            if(mp.find(mask)!=mp.end()){
                ans = max(ans,i - mp[mask]);
            }
            else{
                mp[mask] = i;
            }
        }
        return ans;
        
    }
};