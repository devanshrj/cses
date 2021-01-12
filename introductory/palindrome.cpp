#include <bits/stdc++.h>

// namespaces
using namespace std;


int main() {
    string inp;
    cin >> inp;

    unordered_map<char, int> m; 

    // character counts
    for (int i = 0; i < inp.length(); i++) { 
            m[inp[i]]++; 
    }

    int count = 0;
    char oddChar;
    for (auto i : m) {
        if (i.second % 2 == 1) {
            count++;
            oddChar = i.first;
        }
    }

    if (count > 1 || (count == 1 && inp.length() % 2 == 0)) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    string first = "", second = "";
    for (auto i : m) {
        string s(i.second / 2, i.first);

        // append s to first half of string and prepend to second half
        first += s;
        second = s + second;
    }

    if (count == 1)
        cout << first + oddChar + second;
    else
        cout << first + second;
    
    return 0;
}