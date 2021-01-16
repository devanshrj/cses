#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n, m, elem;
    cin >> n >> m;
    
    // multiset for lower bound
    multiset<int> s;

    REP(i, 0, n) {
        cin >> elem;
        s.insert(elem);
    }

    // lower_bound returns iterator
    REP(i, 0, m) {
        cin >> elem;

        // search for one elem larger so that it-- returns *it <= elem
        auto it = s.lower_bound(elem + 1);
        if (it == s.begin())
            cout << "-1" << '\n';
        else {
            it--;
            cout << (*it) << '\n';
            s.erase(it);
        }
    }

    return 0;
}
