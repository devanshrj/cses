#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

string check(ll x, ll y) {
    if (x > 2 * y || y > 2 * x)
        return "NO";
    if ((x + y) % 3 == 0)
        return "YES";
    return "NO";
}

int main() {
    int n;
    cin >> n;
    
    ll x, y;
    REP(i, 0, n) {
        cin >> x >> y;
        cout << check(x, y) << '\n';
    }

    return 0;
}