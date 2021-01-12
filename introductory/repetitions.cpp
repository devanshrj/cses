#include <bits/stdc++.h>

// namespaces
using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)


int main() {
        string s;
        getline(cin, s);

        int max = 1, count = 1;

        REP(i, 1, s.length()) {
                if (s[i] == s[i - 1]) count++;
                else count = 1;

                if (count > max) max = count;
        }
        cout << max;
        return 0;
}