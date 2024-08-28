class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        while(left < right) {
            int water = min(height[left], height[right]) * (right - left);
            if(water > maxWater) {
                maxWater = max(maxWater, water);
                ++left;
            }
            else
                --right; 
        }
        return maxWater;        
    }
};