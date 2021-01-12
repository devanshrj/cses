#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
        int n;
        ll x, moves = 0;

        cin >> n;
        ll array[n];

        REP(i, 0, n) {
                cin >> x;
                array[i] = x;
        }

        REP(i, 1, n) {
                if (array[i] < array[i - 1]) {
                        moves += (array[i - 1] - array[i]);
                        array[i] = array[i - 1];
                }
        }
        cout << moves;
        return 0;
}
