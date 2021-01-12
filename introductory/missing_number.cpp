#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
        // using summation
        ll actual = 0, expected = 0;
        ll n, x;

        cin >> n;
        expected = n * (n + 1) / 2;

        REP(i, 0, n - 1) {
                cin >> x;
                actual += x;
        }

        cout << expected - actual;
        return 0;
}

