#include <bits/stdc++.h>

using namespace std;

#define m 1000000007
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, x;
    cin >> n >> x;

    int coins[n];
    REP(i, 0, n) {
        cin >> coins[i];
    }

    // count[i] stores count for element i 
    int count[x+1];
    count[0] = 1;

    REP(i, 1, x+1) {
        count[i] = 0;
        for (auto c : coins) {
            if (i - c >= 0) {
                count[i] += count[i-c];
                count[i] %= m;
            }
        }
    }

    cout << count[x] << '\n';
    return 0;
}