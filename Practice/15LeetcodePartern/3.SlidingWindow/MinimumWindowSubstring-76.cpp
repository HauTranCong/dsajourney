class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> pos(128, 0);
        int appear = t.size();
        int bestL = -1;
        int minLength = INT_MAX;

        for(int i = 0; i < t.size(); ++i) {
            ++pos[t[i]];
        }
        
        for(int l = 0, r = 0; r < s.size(); ++r) {
            if(--pos[s[r]] >= 0) {
                --appear;
            }
            while(appear == 0) {
                if((r - l + 1) < minLength) {
                    bestL = l;
                    minLength = min(minLength, r - l + 1);
                }
                if(++pos[s[l++]] > 0)
                    ++appear;
                cout << appear << " " << l << endl;
            }
        }

        return bestL == -1 ? "" : s.substr(bestL, minLength);
    }
};