#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

/* 
O(n^2): DP
O(n log n): Patience Sort
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/

int main() {
    int n, x;
    cin >> n;

    // dp[i] corresponds to last element of active list of length i
    vector<int> dp;

    REP(i, 0, n) {
        cin >> x;

        // find lower bound of x in dp
        auto it = lower_bound(dp.begin(), dp.end(), x);

        // if x > all last elements -> append to dp
        // else -> replace lower bound of x by x
        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }

    cout << dp.size() << '\n';
    return 0;
}