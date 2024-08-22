class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> m{{0,1}};

        for(const int num : nums) {
            prefix += num;       
            int target = prefix - k; 
            auto it = m.find(target);
            if(it != m.end())
                ans += it->second;
            m[prefix]++;
        }
    }
};


// Brute force but 92/93 with TLE
// int total = 0;
// int prefixSum = 0;
// for(int i = 0; i < nums.size(); ++i) {
//     for(int j = i; j < nums.size(); ++j) { 
//         prefixSum += nums[j];
//         total += prefixSum == k ? 1 : 0;
//     }
//     prefixSum = 0;
// }
// return total;
