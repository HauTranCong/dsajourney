class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeStore;
        int ans = INT_MAX;
        for(const string& idx : timePoints) {
            int minutes = stoi(idx.substr(0,2)) * 60 + stoi(idx.substr(3,2));
            timeStore.push_back(minutes);
        }
        sort(timeStore.begin(), timeStore.end());
        
        for(int i = 0; i < timeStore.size() - 1; ++i) {
            ans = min(ans, abs(timeStore[i + 1] - timeStore[i]));
        }
        
        ans = min(ans, (timeStore.front() + 1440)  - timeStore.back());

        return ans;
    }
};