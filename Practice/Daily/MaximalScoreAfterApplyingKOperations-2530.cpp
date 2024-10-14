class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long> pq;
        for(const int& idx : nums)
            pq.push(idx);

        while(k--) {
            long val = pq.top();
            ans += val;
            pq.pop();
            pq.push(ceil((double)val / 3));
        }
        
        return ans;
    }
};