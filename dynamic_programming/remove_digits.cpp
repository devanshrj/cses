#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

int largest_digit(int n) {
    int large = 0, r;
    while (n) {
        r = n % 10;
        large = max(r, large); 
        n = n / 10;
    }
    return large;
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    while (n) {
        n -= largest_digit(n);
        ans++;
    }

    cout << ans << '\n';
    return 0;
}