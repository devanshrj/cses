#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

/*
O(n): https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
*/

int main() {
    int n, x;
    cin >> n;

    vector<int> v(n);
    REP(i, 0, n)
        cin >> v[i];

    stack<int> s;
    REP(i, 0, n) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        
        if (s.empty())
            cout << 0 << ' ';
        else
            cout << s.top() + 1 << ' ';
        
        s.push(i);
    }

    return 0;
}