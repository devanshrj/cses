#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;


int main() {
        ll n, count = 0;
        cin >> n;

        for (int i = 5; n / i >= 1; i *= 5) {
                count += n / i;
        }
        cout << count << '\n';
        return 0;
}