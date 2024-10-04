class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() == 2) {
            return skill[0] * skill[1];
        }
        long long ans = 0;
        vector<pair<int,int>> teams;
        int len = skill.size(); 
        sort(skill.begin(), skill.end());

        int l = 0;
        int r = len - 1;
        long long lastProduct = -1;
        while(l<=r) {
            long long product = skill[l] + skill[r];
            if(product != lastProduct && lastProduct != -1)
                return -1;
            lastProduct = product;
            teams.push_back({skill[l], skill[r]});
            l++;
            r--;
        }

        for(int i = 0; i < teams.size(); ++i) {
            ans += teams[i].first * teams[i].second;
        }

        return ans;
    }
};