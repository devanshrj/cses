#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;


int main() {
        ll n;
        cin >> n;
        while (n) {
                cout << n << " ";
                if (n == 1) break;
                else if (n % 2 == 0) n /= 2;
                else n = 3 * n + 1;
        }
        return 0;
}