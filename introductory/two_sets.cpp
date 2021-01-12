#include <bits/stdc++.h>

// namespaces
using namespace std;

// typedefs
typedef long long ll;

// macros
#define PB push_back

void print(vector<ll> arr) {
    cout << arr.size() << '\n';
    for (ll i : arr)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ll n;
    cin >> n;

    ll total = n * (n + 1) / 2;
    
    if (total % 2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    vector<ll> set1, set2;
    total /= 2LL;

    while (n) {
        if (total - n >= 0) {
            set1.PB(n);
            total -= n;
        }
        else {
            set2.PB(n);
        }
        n--;
    }
    print(set1);
    print(set2);
    return 0;
}