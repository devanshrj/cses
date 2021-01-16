#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> map;
    int elem;
    
    REP(i, 0, n) {
        cin >> elem;
        map[elem] = i;
    }
    
    int ans = 1, current = map[1];
    
    REP(i, 2, n + 1) {
        if (map[i] < current)
            ans++;
        current = map[i];
    }
    cout << ans << '\n';
    return 0;
}
