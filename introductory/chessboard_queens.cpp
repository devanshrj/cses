#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

vector<string> s(8);
vector<bool> col(8), diag1(8), diag2(8);
int ans;

void search(int y) {
    if (y == 8) {
        ans++;
        return;
    }

    REP (x, 0, 8) {
        if (col[x] || diag1[x + y] || diag2[x - y + 8] || s[y][x] == '*') continue; 
        col[x] = diag1[x + y] = diag2[x - y + 8] = 1; 
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + 8] = 0;
    }
}

int main() {
    REP (i, 0, 8)
        cin >> s[i];

    search(0);
    cout << ans << '\n';

    return 0;
}
