#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n;
    cin >> n;

    int c[n], sum = 0;
    REP(i, 0, n) {
        cin >> c[i];
        sum += c[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;
    REP(i, 1, n+1) {
        REP(j, 0, sum+1) {
            dp[i][j] = dp[i-1][j];
            if (c[i-1] <= j && dp[i-1][j-c[i-1]])
                dp[i][j] = true;
        }
    }
    
    vector<int> v;
    REP(i, 1, sum+1) {
        if (dp[n][i])
            v.push_back(i);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i : v)
        cout << i << ' ';
    cout << '\n';

    return 0;
}