/*
Codeforces Round 1005 (Div. 2)
https://codeforces.com/contest/2064/problem/C
C. Remove the Ends
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<ll>> coins;
int n;

void input() {
    cin >> n;
    coins.resize(n);
    for(int i = 0; i < n; ++i) {
        int length; cin >> length;
        for(int j = 0; j < length; ++j) {
            ll value; cin >> value;
            coins[i].push_back(value);
        }
    }
} 

void solve() {
    for(int i = 0; i < n; ++i) {
        int l = coins[i].size();
        vector<ll> pPrefix(l, 0);
        vector<ll> nPrefix(l, 0);
        ll posSum = 0;
        ll negSum = 0;
        ll maxSum = 0;
        for(int j = 0; j < l; ++j) {
            if(coins[i][j] > 0) {
                posSum += coins[i][j];
            } else {
                negSum += abs(coins[i][j]);
            }
            pPrefix[j] = posSum;
            nPrefix[j] = negSum;
        }
        maxSum = max(posSum, negSum);
        for(int j = 0; j < l; ++j) {
            maxSum = max(maxSum, pPrefix[j] + negSum - nPrefix[j]);
        }
        std::cout << maxSum << "\n";
    }
}

int main()
{
    input();
    solve();
    return 0;
}
