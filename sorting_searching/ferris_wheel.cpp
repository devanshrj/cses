#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef vector<int> vi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)


int main() {
    int n, x;
    cin >> n >> x;

    vi weights(n);

    REP(i, 0, n) {
        cin >> weights[i];
    }
    sort(all(weights));

    int count = 0;
    for (int i = 0, j = n - 1; i < n && j >= i; ) {
        if (weights[i] + weights[j] <= x)
            count++, i++, j--;
        else
            count++, j--;
    }

    cout << count << '\n';
    return 0;
}
