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

    ll arr[n];

    REP(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int count = 1;
    REP(i, 0, n - 1) {
        if (arr[i] != arr[i + 1])
            count++;
    }
    cout << count << '\n';

    return 0;
}