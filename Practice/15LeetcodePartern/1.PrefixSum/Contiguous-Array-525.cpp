class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> cntMap;
        int count = 0;
        int maxlength = 0;
        cntMap[0] = -1;
        for(int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 0 ? -1 : 1;
            if(cntMap.find(count) != cntMap.end()) 
                maxlength = max(maxlength, i - cntMap[count]);
            else
                cntMap[count] = i;
        }
        return maxlength;
    }
};