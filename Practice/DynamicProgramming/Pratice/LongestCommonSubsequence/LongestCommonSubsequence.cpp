#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int stackCountNative = 0;
int stackCountDP = 0;
vector<vector<int>> memo;
vector<vector<int>> tubu;

int lcs(string &S1, string &S2, int m, int n){
    stackCountNative++;
    if (m == 0 || n == 0)
        return 0;
    if (S1[m - 1] == S2[n - 1])
        return 1 + lcs(S1, S2, m - 1, n - 1);
    else {
        return max(lcs(S1, S2, m - 1, n), lcs(S1, S2, m, n - 1));
    }
}

int lcs_memo(string &S1, string &S2, int m, int n) {
    stackCountDP++;
    if (m == 0 || n == 0)
        return 0;
    if (memo[m][n] != -1)
        return memo[m][n];
    if (S1[m - 1] == S2[n - 1])
        return memo[m][n] = 1 + lcs_memo(S1, S2, m - 1, n - 1);
    
    return memo[m][n] = max(lcs_memo(S1, S2, m - 1, n), lcs_memo(S1, S2, m, n - 1));
}

int lcs_tubu(string &S1, string &S2, int m, int n) {
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(S1[i - 1] == S2[j - 1])
                tubu[i][j] = 1 + tubu[i - 1][j - 1];
            else 
                tubu[i][j] = max(tubu[i-1][j], tubu[i][j-1]);
        }
    }
    return tubu[m][n];
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();
    memo.resize(m + 1, vector<int>(n + 1, -1));
    tubu.resize(m + 1, vector<int>(n + 1, 0));
    
    cout << "-----------------------Native Approach-----------------------\n";
    cout << "Length of LCS using rescursive is " << lcs(S1, S2, m, n) << "\n";
    cout << "stackCount_rescursive: " << stackCountNative << "\n";
    
    cout << "---------------------Dynamic Programming---------------------\n";
    cout << "Length of LCS using memoization is " << lcs_memo(S1, S2, m, n) << "\n";
    cout << "stackCount_dynamic: " << stackCountDP << "\n";
    cout << "Length of LCS using tubulation is " << lcs_tubu(S1, S2, m, n) << "\n";
    
    return 0;
}

// -----------------------Native Approach-----------------------
// Length of LCS using rescursive is 4
// stackCount_rescursive: 346
// ---------------------Dynamic Programming---------------------
// Length of LCS using memoization is 4
// stackCount_dynamic: 45
// Length of LCS using tubulation is 4