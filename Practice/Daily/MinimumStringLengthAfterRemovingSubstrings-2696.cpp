class Solution {
public:
    int minLength(string s) {
        while(!s.empty()) {
            bool isBreak = false; 
            for(int i = 0; i < s.length() - 1 && s.length() >= 2; ++i) {
                if(s[i] == 'A' && s[i+1] == 'B') {
                    s.erase(i, 2);
                    isBreak = true;
                    break;
                } 
            }
            for(int i = 0; i < s.length() - 1 && s.length() >= 2; ++i) {
                if(s[i] == 'C' && s[i+1] == 'D') {
                    s.erase(i, 2);
                    isBreak = true;
                    break;
                }
            }
            if(isBreak == false) {
                break;
            }
        }
        return s.length();
    }
};