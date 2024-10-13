class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> mergedList;
        int numsGroup = nums.size();
        int totalGroup = 0;
        for(const auto& list : nums) {
            for(const int& idx : list)
                mergedList.push_back({idx, totalGroup});        
            totalGroup++;
        }
        sort(mergedList.begin(), mergedList.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });

        unordered_map<int,int> groupCnt;
        int startWindow = 0;
        vector<int> ans = {-100000, 100000};

        for(int endWindow = 0; endWindow < mergedList.size(); ++endWindow) {
            int currentValue = mergedList[endWindow].first;
            int currentGroup = mergedList[endWindow].second;
            groupCnt[currentGroup]++;
            while(groupCnt.size() == totalGroup) {
                int startWindowValue = mergedList[startWindow].first;
                int startWindowGroup = mergedList[startWindow].second;
                int currentRange = currentValue - startWindowValue;
                long bestRange = ans[1] - ans[0];
                if(currentRange < bestRange || (currentRange == bestRange && startWindowValue < ans[0])) {
                    ans[0] = startWindowValue;
                    ans[1] = currentValue;
                }
                if(--groupCnt[startWindowGroup] == 0) {
                    groupCnt.erase(startWindowGroup);
                }
                startWindow++;
            }
        }
        // for(const auto& list : mergedList) {
        //     cout << list.first << " " << list.second << endl;  
        // }

        return ans;
    }
};