class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long prefixSum = 0;
        for(int i = 0; i < chalk.size(); ++i) {
            prefixSum += chalk[i];
        }
        int cycle = k / prefixSum;
        prefixSum *= cycle;

        for(int i = 0; i < chalk.size(); ++i) {
            prefixSum += chalk[i];
            if(prefixSum > k)
                return i;
        }

        return -1;
    }
};

// Worst case: O(2n)
// Best case: O(n + (n - i))