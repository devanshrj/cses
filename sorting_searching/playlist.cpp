#include <bits/stdc++.h>

using namespace std;

// macros
#define REP(i,a,b) for (int i = a; i < b; i++)

// https://www.geeksforgeeks.org/longest-subarray-consisiting-of-unique-elements-from-an-array/
int main() {
    int n;
    cin >> n;

    int arr[n];
    REP(i, 0, n) {
        cin >> arr[i];
    }

    // sliding window: O(n)
    // last index of every number
    map<int, int> index;
    int res = 0, i = 0;     // i is start of sliding window

    REP(j, 0, n) {
        // update window
        i = max(i, index[arr[j]]);

        // update res if larger window
        res = max(res, j - i + 1);

        // update last index of j
        index[arr[j]] = j + 1;
    }

    cout << res << '\n';
    return 0;
}