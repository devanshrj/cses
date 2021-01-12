#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
        int n;
        cin >> n;

        ll x, y;
        ll value;
        REP(i, 0, n) {
                cin >> y >> x;
                if (x >= y) {
                        if (x % 2 == 1)
                                value = (x * x) - (y - 1);
                        else
                                value = ((x - 1) * (x - 1)) + y;
                }
                else {
                        if (y % 2 == 0)
                                value = (y * y) - (x - 1);
                        else
                                value = ((y - 1) * (y - 1)) + x;
                }
                cout << value << '\n';
        }
        return 0;
}