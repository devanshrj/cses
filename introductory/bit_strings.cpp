#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define m 1000000007
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
        int n;
        cin >> n;

        ll result = 1;
        REP(i, 1, n + 1) {
                result = (result * 2) % m;
        }
        cout << result << '\n';
        return 0;
}

