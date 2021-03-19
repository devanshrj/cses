#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, x;
    cin >> n >> x;

    int c[n];
    REP(i, 0, n) {
        cin >> c[i];
    }

    // count[i] stores count for element i 
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));

    // base condition
    dp[0][0] = 1;
    
    REP(i, 1, n+1) {
        REP(j, 0, x+1) {
            dp[i][j] = dp[i-1][j];
            if (c[i-1] <= j)
                (dp[i][j] += dp[i][j-c[i-1]]) %= mod;
        }
    }

    cout << dp[n][x] << '\n';
    return 0;
}