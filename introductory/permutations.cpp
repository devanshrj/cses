#include <bits/stdc++.h>

// namespaces
using namespace std;


int main() {
        int n;
        cin >> n;
        
        if (n == 1)
                cout << 1 << '\n';
        else if (n > 1 && n < 4) 
                cout << "NO SOLUTION" << '\n';
        // print all even numbers first and then odd
        else {
                for (int i = 2; i < n + 1; i += 2)
                        cout << i << ' ';
                for (int i = 1; i < n + 1; i += 2)
                        cout << i << ' ';
        }
        return 0;
}