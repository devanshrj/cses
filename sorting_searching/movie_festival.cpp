#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef pair<int,int> pi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)


int main() {
    int n;
    cin >> n;

    vector<pi> times(n);
    // end time is first element of pair and start time is second
    REP(i, 0, n) {
        cin >> times[i].second;
        cin >> times[i].first;
    }
    sort(all(times));

    int ans = 1;
    pi current = times[0];
    REP(i, 0, n) {
        if (times[i].second >= current.first) {
            ans++;
            current = times[i];
        }
    }

    cout << ans << '\n';
    return 0;
}
