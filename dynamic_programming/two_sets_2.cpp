#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)
#define mod 1000000007

int main() {
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    sum /= 2;
    int dp[n][sum+1];

    // base conditions
    REP(j, 0, sum+1)
        dp[0][j] = 0;
    REP(i, 0, n)
        dp[i][0] = 1;

    REP(i, 1, n) {
        REP(j, 0, sum+1) {
            dp[i][j] = dp[i-1][j];
            if (i <= j)
                (dp[i][j] += dp[i-1][j-i]) %= mod;
        }
    }
    
    cout << dp[n-1][sum] << '\n';
    return 0;
}