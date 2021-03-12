#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef pair<int,int> pi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, a, d;
    cin >> n;

    ll ans = 0, time = 0;
    multimap<int, int> m;

    REP(i, 0, n) {
        cin >> a >> d;
        m.insert(pi (a, d));
    }

    for (auto i : m) {
        time += i.first;
        ans += (i.second - time);
    }

    cout << ans << '\n';
    return 0;
}