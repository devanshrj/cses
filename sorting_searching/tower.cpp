#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef vector<int> vi;

// macros
#define PB push_back
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)

// tower stores top element of a stack
// if tower has an upper bound for an elem, the elem is pushed to that index
// else elem makes a new  and count is increased

int main() {
    int n;
    cin >> n;

    int elem, ans = 0;
    vi tower;

    REP(i, 0, n) {
        cin >> elem;

        auto it = upper_bound(all(tower), elem);
        if (it == tower.end()) {
            ans++;
            tower.PB(elem);
        }
        else {
            tower[it - tower.begin()] = elem;
        }
    }

    cout << ans << '\n';
    return 0;
}
