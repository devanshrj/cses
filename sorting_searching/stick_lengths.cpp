#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef vector<int> vi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()

int main() {
    int n;
    cin >> n;

    vi len(n);
    REP(i, 0, n) {
        cin >> len[i];
    }
    sort(all(len));

    int median = len[n / 2];
    ll cost = 0;
    REP(i, 0, n) {
        cost += abs(len[i] - median);
    }

    cout << cost << '\n';
    return 0;
}
