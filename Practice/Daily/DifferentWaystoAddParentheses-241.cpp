class Solution {
public:
    vector<int> dfs(const string& exp) {
        vector<int> result;

        if(!exp.empty() && all_of(exp.begin(), exp.end(), ::isdigit)) {
            result.push_back(stoi(exp));
            return result;
        }

        for(int i = 0; i < exp.size(); ++i) {
            char c = exp[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> leftResult = dfs(exp.substr(0, i));
                vector<int> rightResult = dfs(exp.substr(i + 1));
                for(int a : leftResult) {
                    for(int b : rightResult) {
                        if(c == '+')
                            result.push_back(a + b);
                        else if(c == '-')
                            result.push_back(a - b);
                        else
                            result.push_back(a * b);
                    }
                }
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
};

// operators = parentheses pair
//              2 - 1 - 1
//  (2 - 1) - 1     2 - (1 - 1)