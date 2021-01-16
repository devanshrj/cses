#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n, x;
    cin >> n >> x;

    // one-pass hash table
    // map maintains value and index
    map<int, int> map;
    int num;

    REP(i, 1, n + 1) {
        cin >> num;

        // complement found
        if (map.count(x - num)) {
            cout << map[x - num] << ' ' << i << '\n';
            return 0;
        }
        map[num] = i;
    }
    
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
