#include <bits/stdc++.h>
using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)
#define M 5000
#define N 5000


int main() {
    static int dp[M+1][N+1];

    string X, Y;
    cin >> X;
    cin >> Y;

    int m = X.length(), n = Y.length();

    // base conditions: one string is empty
    REP(i, 0, m+1)
        dp[i][0] = i;
    REP(j, 0, n+1)
        dp[0][j] = j;

    REP(i, 1, m+1) {
        REP(j, 1, n+1) {
            // equal characters so no operation required
            if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1];
            // insertion, deletion or replace require 1 more operation
            else
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    
    cout << dp[m][n] << '\n';
    return 0;
}