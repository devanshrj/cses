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

    ll weights[n];
    ll sum1, sum2, diff;
    ll min = std::numeric_limits<ll>::max();

    REP(i, 0, n) {
        cin >> weights[i];
    }

    // check all subsets for min value
    for (int b = 0; b < (1 << n); b++) {
        sum1 = 0;
        sum2 = 0;

        // sum1 = sum of subset weights
        // sum2 = sum of complement subset weights
        for (int i = 0; i < n; i++) {
            if (b & (1 << i))
                sum1 += weights[i];
            else
                sum2 += weights[i];
        }
        
        diff = abs(sum1 - sum2);

        if (diff < min)
            min = diff;
    }

    cout << min << '\n';

    return 0;
}
