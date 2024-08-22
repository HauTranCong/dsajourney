class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i; j < nums.size(); ++j) { 
                prefixSum += nums[j];
                total += prefixSum == k ? 1 : 0;
                // cout << prefixSum << "\n";
            }
            prefixSum = 0;
        }

        return total;
    }
};
