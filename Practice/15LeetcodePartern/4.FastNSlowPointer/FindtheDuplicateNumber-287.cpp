class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// 287 - Hashmap to count appearance times, Runtime 6.98%, Memory 10.12%
// int findDuplicate(vector<int>& nums) {
//     map<int,int> m;
//     for(int i = 0; i < nums.size(); ++i){
//         if(++m[nums[i]] > 1)
//             return nums[i];
//     }
//     return 0;
// }