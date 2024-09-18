class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> strNums;
        for(const int& idx : nums)
            strNums.push_back(to_string(idx));

        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });

        if(strNums.front() == "0")
            return "0";

        for(int i = 0; i < strNums.size(); ++i) {
            ans += strNums[i];
        }

        return ans;
    }
};

// 99 9 98 97 
// 9 99 98 97
// 1 2 100 3
// 56 50