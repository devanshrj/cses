#include <bits/stdc++.h>

using namespace std;

#define m 1000000007
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n;
    cin >> n;

    // count[i] stores count for element i 
    int count[n+1];
    count[0] = 1;

    REP(x, 1, n+1) {
        count[x] = 0;
        REP(i, 1, 7) {
            if (x - i >= 0) {
                count[x] += count[x-i];
                count[x] %= m;
            }
        }
    }

    cout << count[n] << '\n';
    return 0;
}