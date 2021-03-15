#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, x, c;
    cin >> n >> x;

    vector<int> dp(x+1, MAX);
    dp[0] = 0;

    REP(i, 0, n) {
        cin >> c;
        REP(j, c, x+1) {
            dp[j] = min(dp[j], dp[j-c]+1);
        }
    }

    cout << (dp[x] == MAX ? -1 : dp[x]) << '\n';
    return 0;
}