#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef vector<int> vi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n;
    cin >> n;

    vector<ll> num(n);
    REP(i, 0, n)
        cin >> num[i];
    
    ll best = -10, sum = -10;
    REP(i, 0, n) {
        sum = max(num[i], sum + num[i]);
        best = max(best, sum);
    }
    cout << best << "\n";

    return 0;
}
