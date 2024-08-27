class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(count(nums.begin(), nums.end(), 0) == nums.size())
            return {{0,0,0}};
        vector<vector<int>> ans;
        int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0) {
                ans.push_back({nums[i],nums[j],nums[k]});
                --k;
            } else if(sum > 0) {
                --k;
            } else {
                ++i;
                j = i + 1;
            }
        }
        return ans; 
    }
};

//  -4  -1  -1  0   1   2
//  i   j               k
//      i   j           k   -> take it
//      i   j       k
//          i   j   k       -> take it  

// be careful with 0, 0, 0, 0 cases