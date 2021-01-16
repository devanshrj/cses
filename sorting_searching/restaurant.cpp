#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef vector<int> vi;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)


int main() {
    int n;
    cin >> n;

    vi arrive(n), leave(n);
    REP(i, 0, n) {
        cin >> arrive[i];
        cin >> leave[i];
    }

    sort(all(arrive));
    sort(all(leave));

    int ans = -1, count = 0;
    for (int i = 0, j = 0; i < n && j < n; ) {
        if (arrive[i] < leave[j]) {
            count++, i++;
        }
        else {
            count--; j++;
        }
        ans = max(count, ans);
    }
    
    cout << ans << '\n';
    return 0;
}
