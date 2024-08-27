class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(count(nums.begin(), nums.end(), 0) == nums.size())
            return {{0,0,0}};
        vector<vector<int>> ans;
        map<vector<int>, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    m[{nums[i],nums[j],nums[k]}] = 1;
                    --k;
                } else if(sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }            
        }

        for(const auto& it : m)
            ans.push_back(it.first);
            
        return ans; 
    }
};
// be careful with 0, 0, 0, 0 cases

//  -4  -1  -1  0   1   2
//  i   j               k
//      i   j           k   -> take it
//      i   j       k
//          i   j   k       -> take it  

//  -2  0   1   1   2
//  i   j           k   -> take it
//  i   j       k       