#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp> // pbds
#include<ext/pb_ds/tree_policy.hpp>
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
#define in(arr) for(int i = 0; i < n; i++) cin >> (arr)[i];
#define print(a) for(int i = 0; i < (a).size(); i++) { cout << (a)[i] << " "; } cout << "\n";

const int MOD = 998244353;
const int mod = 1e18+7;
vector<int>isprime;
void sieve(){isprime.resize(3000001, 1);isprime[0] = isprime[1] = 0;for(int i = 2; i*i <=3000000; i++){if(isprime[i]){for(int j = i*i; j<= 3000000; j+= i){isprime[j] = 0;}}}}
void All_Fact(int n, vector<int>&a, bool &flag) { for(int i = 2; i * i <= n; i++) { if(n % i == 0) {if(i > 1) if(!isprime[i]){flag = 1;break;} a.push_back(i);if(n / i != i) { if(!isprime[n/i]){flag = 1;break;}a.push_back(n / i);}}}}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_pow(int base, int power, int m){int res=1;while(power){if(power&1){power = power-1;res = (res*base)%m;}else{power = power/2;base = (base*base)%m;}}return (res)%m;}
int miv_coprime(int a, int b){return mod_pow(a, b-2, b);}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, miv_coprime(b, m), m) + m) % m;}



void solve() {
    
}



int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif


    int Testcase = 1;
    cin >> Testcase;
    for (int i = 1; i <= Testcase; i++) {
        // cout << i << ": " ;
        solve();
        // cout << "\n";
    }
    
    return 0;
}


/*
    visited in case of recalculation - not needed
    ans += '0' in O[1] and 
    C++ recursion stack depth is limited (typically ~10⁴ to 10⁵).
    (ALERT :::: ans = ans + '0' in o[n])
    MLE -> avoid storing
*/