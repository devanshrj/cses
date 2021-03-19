#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, x;
    cin >> n >> x;

    int price[n], page[n];
    REP(i, 0, n)
        cin >> price[i];
    
    REP(i, 0, n)
        cin >> page[i];

    // DP matrix
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));

    REP(i, 1, n+1) {
        REP(j, 0, x+1) {
            dp[i][j] = dp[i-1][j];
            if (price[i-1] <= j)
                dp[i][j] = max(page[i-1] + dp[i-1][j-price[i-1]], dp[i][j]);
        }
    }

    cout << dp[n][x] << '\n';
}