class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1;
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
            maxVal = max(maxVal, nums[i]);

        int count = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == maxVal && nums[i + 1] == maxVal)
                ++count;
            else
                count = 1;
            ans = max(ans, count);
        }
     
        return ans;
    }
};