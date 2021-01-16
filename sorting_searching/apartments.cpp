#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // desired: applicant specs, actual: actual sizes
    vector<int> desired(n), actual(m);

    REP(i, 0, n) {
        cin >> desired[i];
    }

    REP(i, 0, m) {
        cin >> actual[i];
    }

    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());

    int count = 0;
    
    for (int i = 0, j = 0; i < n && j < m; ) {
        if (abs(desired[i] - actual[j]) <= k)
            count++, i++, j++;
        else if (desired[i] - k > actual[j])
            j++;
        else
            i++;
    }

    cout << count << '\n';
    return 0;
}