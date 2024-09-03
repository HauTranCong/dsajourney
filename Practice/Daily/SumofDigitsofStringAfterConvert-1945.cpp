class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> v;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            v.push_back(s[i] - 97 + 1);
        }

        for(int i = 0; i < k; ++i) {
            int tmp = 0;
            while(!v.empty()) {
                int value = v.front();
                v.erase(v.begin());
                while(value) {
                    tmp += value % 10;
                    value /= 10;
                }
            }
            v.push_back(tmp);
            ans = tmp;
        }

        return ans;
    }
};