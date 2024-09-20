class Solution {
public:
    string shortestPalindrome(string s) {
        if(!s.length())
            return "";
        if(isValidPalindrome(s))
            return s;
        string ans = s;
        string tmp;
        for(int r = s.length() - 1; r > 0; --r) {
            if(isValidPalindrome(ans))
                return ans;
            tmp = tmp + s[r];
            ans = tmp + s;
        }
        return ans;
    }

    bool isValidPalindrome(string s) {
        string P = s;
        reverse(P.begin(), P.end());
        if(s == P)
            return true;
        return false;
    }
};

// must perform transform
// abcde -> edcb a bcde
// aacecaaa -> a aacecaaa
// aaa -> aa aaa

// Sol 1:
// bruteforce from right to left by append last char to front
// 1. push the last char to front
// 2. Check if valid palindrome 
// 3. return str valided 
// time(O(n^2))
// space(O(1))