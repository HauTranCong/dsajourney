class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double slideWindow = 0;
        double ans = INT_MIN;

        for(int i = 0; i < k; ++i)
            slideWindow += nums[i];
        ans = max(ans, slideWindow / k);

        for(int i = 1; i <= nums.size() - k; ++i) {
            slideWindow += nums[i + k - 1] - nums[i - 1];
            ans = max(ans, slideWindow / k);
        }
        
        return ans;
    }
};