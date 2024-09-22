class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> results;
        for(int i = 1; i <= 9; ++i) {
            dfs(i, n, results);
        }
        return results;
    }
    void dfs(int i, const int& n, vector<int>& results) {
        if(i > n)
            return;
        results.push_back(i);
        for(int j = 0; j < 10; ++j) {
            dfs(i * 10 + j, n, results);
        }
    }
};

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> result;
//         int current = 1;
//         for (int i = 0; i < n; ++i) {
//             result.push_back(current);
//             if (current * 10 <= n) {
//                 current *= 10;
//             } else {
//                 while (current % 10 == 9 || current + 1 > n) {
//                     current /= 10;
//                 }
//                 ++current;
//             }
//         }
//         return result; 
//     }
// };