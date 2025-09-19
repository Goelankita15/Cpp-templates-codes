#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>  // pbds
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#include "algo-debugfile.cpp"
#else
#define dbg(x)
#endif

#define inf 1e18
#define int long long
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define in(arr) for (int i = 0; i < n; i++) cin >> (arr)[i];
#define print(a) for (int i = 0; i < (a).size(); i++) { cout << (a)[i] << " "; } cout << "\n";

int mod = 1e9 + 7;

// Custom function to read __int128 from input
void readInt128(__int128 &x) {
    string s;
    cin >> s;
    x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0');  // Convert each character to the corresponding integer
    }
}

// Custom function to print __int128
void printInt128(__int128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    string result;
    while (x > 0) {
        result.push_back('0' + (x % 10));  // Get the last digit
        x /= 10;
    }
    reverse(result.begin(), result.end());  // Reverse to get the correct order
    cout << result;
}

const int Modulo = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> copy = arr;

    auto find = [&](int K) {
        arr = copy;
        for (int i = 60; i >= 0; i--) {
            __int128 op = 0;
            if (K <= 0) break;
            vector<int> needed(n, 0);
            __int128 period = (1LL << i);
            __int128 dividend = (1LL << (i + 1));
            for (int j = 0; j < n; j++) {
                if ((arr[j] & (1LL << i))) continue;
                op += max((period - (arr[j] % dividend)), 0LL);
                needed[j] = max((period - (arr[j] % dividend)), 0LL);
            }
            if (K > 0 && op <= K) {
                K = K - op;
                for (int j = 0; j < n; j++) {
                    arr[j] += needed[j];
                }
            }
        }

        __int128 andValue = arr[0];
        for (int j = 0; j < n; j++) {
            andValue = (andValue & arr[j]);
        }
        return andValue;
    };

    for (int i = 0; i < q; i++) {
        int K;
        cin >> K;
        __int128 answer = find(K);
        printInt128(answer);
        cout << "\n";
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int Testcase = 1;
    // cin >> Testcase;
    for (int i = 0; i < Testcase; i++) {
        // cout << "Case #" << i+1 << ": " ;
        solve();
    }
    return 0;
}
