#include <bits/stdc++.h>

// namespaces
using namespace std;

void permute(string s) {
        sort(s.begin(), s.end());

        do {
                cout << s << '\n';
        } while (next_permutation(s.begin(), s.end()));
}

int factorial(int n) {
        if (n == 1)
                return 1;
        else
                return n * factorial(n - 1);
}

int main() {
        string inp;
        cin >> inp;

        unordered_map<char, int> m; 

        for (int i = 0; i < inp.length(); i++) { 
                m[inp[i]]++; 
        } 

        int perm = factorial(inp.length());
        for (auto i : m) {
                perm /= factorial(i.second);
        }

        cout << perm << '\n';
        permute(inp);

        return 0;
}

