//Shri Shivay Namastubhayam!
#include"bits/stdc++.h"
/*Policy Based Data-Structure*/
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

#define S_peed_u_p                                   ios_base::sync_with_stdio(0); cin.tie(0); 
#define Yes                                          cout <<"Yes\n";
#define No                                           cout <<"No\n";
#define YES                                          cout <<"YES\n";
#define NO                                           cout <<"NO\n";
#define sp                                           <<" "<<
#define ndl                                          "\n"
#define pb                                           push_back
#define pp                                           pop_back
#define sz                                           size()
#define int                                          long long
#define nlin                                         cout <<"\n";
#define r_deci(x)                                    <<fixed<<setprecision(x)<< //for setting a fixed number of decimal places
#define gcd(a,b)                                     __gcd(a,b)
#define all(x)                                       (x).begin(), (x).end()
#define rall(x)                                      (x).rbegin(),(x).rend()
#define F                                            first
#define S                                            second
#define minus1                                       cout <<"-1"<< endl;
#define one                                          cout <<"1" << endl;
#define zero                                         cout <<"0" << endl;
#define FOR(i, a, n)                                 for(ll i = a; i<n; i++)
#define BAC(i, a, n)                                 for(ll i = n-1; i>=a; i--)
#define read(arr)                                    for(ll i =0; i<n; i++)cin>>(arr)[i];
#define print(a)                                     for(ll i =0; i<(a).size(); i++){ cout << (a)[i] <<" ";} nlin
//Number of bits in a number => log2(n) + 1

#ifndef ONLINE_JUDGE
#define dbg(x)  cerr << #x << " ";_print(x); cerr << endl;
#else
#define dbg(x)
#define deb(...) 63;
#endif


// typedef tree<int, null_type, less<int>/*greater<int>*/, rb_tree_tag, tree_order_statistics_node_update>  pbds; 
// find_by_order, order_of_key <= Operations of Ordered Sets
// order_of_key (val): returns the no. of values less than val
// *find_by_order (k): returns the index of the element in form of iterator

typedef long long                                    ll;
typedef vector<ll>                                   vi;
typedef vector<pair<ll, ll>>                         vpii;
typedef set<ll>                                      si;
typedef unordered_set<ll>                            usi;
typedef pair<ll, ll>                                 pii;
typedef map<ll, ll>                                  mii;
typedef unordered_map<ll, ll>                        umii;
typedef unsigned long long                           ull;

int M=1e9+7;
int M1 = 998244353;
void _print(int a){cerr << a;}
void _print(char a){cerr << a;}
void _print(string a){cerr << a;}
void _print(double a){cerr << a;}
void _print(bool a){cerr << a;}
void _print(long double a){cerr << a;}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int factorial(int n){if(n <= 1) return 1; return factorial(n-1)*n;};
int nCr(int n,int r){int num = factorial(n); int den1 = factorial(r); int de2 = factorial(n-r); return num/(den1*de2);}
vector<ll> sieve(ll n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_pow(ll base, ll power, int m){ll res=1;while(power){if(power&1){power = power-1;res = (res*base)%m;}else{power = power/2;base = (base*base)%m;}}return (res)%m;}
ll miv_coprime(int a, int b){return mod_pow(a, b-2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, miv_coprime(b, m), m) + m) % m;}//only for prime m
void factors(ll n, vector<ll>&f){for(int x = 2; x*x <= n; x++) {while (n%x == 0) {f.push_back(x);n /= x;}}if (n > 1) f.push_back(n);}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //v[0] is x and v[1] is y in ax + by = gcd(a, b) pass an arry of size = 3
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//templates
template<class T, class V>void _print(pair<T, V> p){cerr <<"["; _print(p.first); cerr <<" "; _print(p.second); cerr <<"]";}
template<class T> void _print(vector<T> v){cerr << "[";for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v){cerr << "[";for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(map <T, V> m){cerr <<"{";for(auto i : m){_print(i) ; cerr <<" ";} cerr <<"}";}
template<class T> void _print(multiset <T> mst){cerr << "[";for(T i : mst){_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(vector<pair<T,V>>vp){for(auto i : vp){_print(i); cerr << "\n";}}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* In constant space and time
	
	// C++20
	#include <bit>
	int log2_floor(unsigned long i) {
	    return std::bit_width(i) - 1;
	}

	// pre C++20
	int log2_floor(unsigned long long i) {
	    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

*/


/*
// logarithms can also be precomputed
int lg[MAXN+1];
lg[1] = 0;
for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i/2] + 1;

 */
// O[logMax]
long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}
int Query(int L, int R, vector<vector<int>>&v){
	int len = R-L+1;
	len = log2(len); // Caution! : Precision Errors possible
	return min(v[L][len], v[R-(1<<len)+1][len]); // overalpping range posiible in idempotent quries O[1];
	//otherwise O[log2(n)] 
}
void solve(){
	// time complexity of precomputation is O[nlog(n)]
	int n, q;
	cin >> n >> q;
	vector<int>a(n);
	int len = log2(n);
	vector<vector<int>>v(n, vector<int>(len+1));
	for(int i =0; i<n; i++){
		cin >> a[i];
		v[i][0] = a[i];
	}
	//Building Sparse table
	for(int j = 1; j <= len; j++){
		for(int i =0; i<= n - (1<<j); i++){ // i+(1<<j)-1 < n
			v[i][j] = min(v[i][j-1], v[(i+(1<<(j-1)))][j-1]);
		}
	}


	for(int i =0; i<q; i++){
		int x, y;
		cin >> x >> y;
		x = x-1, y = y-1;
		// if(x == y){
		// 	cout << a[x] << "\n";
		// 	return;
		// }
		cout << Query(x, y, v) << "\n";
	}
}
int32_t main() {
    S_peed_u_p
   
   #ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
   #endif
   // auto start1 = high_resolution_clock::now();
   // Seive();
   int Test = 1;
   // cin >> Test;
   for(int i=1; i<=Test; i++){
      //cout<<"Case #"<<i<<": \n";
      solve();
   }
}
