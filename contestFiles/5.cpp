#include<bits/stdc++.h>
using namespace std;

string convert(int n, int base) {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    while (n > 0) {
        result += digits[n % base];
        n /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;

    string ans = "";
    for (int base = 2; base <= 36; base++) {
        string b = convert(n, base);
        if (ans == "" || b < ans) {
            ans = b;
        }
    }

    cout << ans;
    return 0;
}
