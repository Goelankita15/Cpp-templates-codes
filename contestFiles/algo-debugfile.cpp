//Shri Shivay Namastubhayam!

/*Policy Based Data-Structure*/
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


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
#define FOR(i, a, n)                                 for(ll i = a; i<n; i++)
#define BAC(i, a, n)                                 for(ll i = n-1; i>=a; i--)
//Number of bits in a number => log2(n) + 1

#ifndef ONLINE_JUDGE
#define dbg(x)  cerr << #x << " ";_print(x); cerr << endl;
#else
#define dbg(x)
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

// int M=1e9+7;
// int M1 = 998244353;
void _print(int a){cerr << a;}
void _print(char a){cerr << a;}
void _print(string a){cerr << a;}
void _print(double a){cerr << a;}
void _print(bool a){cerr << a;}
void _print(long double a){cerr << a;}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
string dB(int n){string ans = "";for(int i = 43; i>=0; i--){int k = n>>i;if(k&1) ans += '1';else ans += '0';}return ans;}

// class Mint {
// public:
//     long long a;
//     Mint(long long a = 0) {this->a = ((a % MOD) + MOD) % MOD;}
//     Mint operator+(const Mint &b) const {return Mint((a + b.a) % MOD);}
//     Mint operator-(const Mint &b) const {return Mint((a - b.a + MOD) % MOD);}
//     Mint operator*(const Mint &b) const {return Mint((a * b.a) % MOD);}
//     Mint power(long long exp) const {Mint result = 1;Mint base = *this;while (exp > 0) {if (exp & 1){result = result * base;}base = base * base;exp >>= 1;}return result;}
//     Mint inverse() const {return power(MOD - 2);}
//     Mint operator/(const Mint &b) const {return *this * b.inverse();}
//     Mint& operator+=(const Mint &b) {a = (a + b.a) % MOD;return *this;}
//     Mint& operator-=(const Mint &b) {a = (a - b.a + MOD) % MOD;return *this;}
//     Mint& operator*=(const Mint &b) {a = (a * b.a) % MOD;return *this;}
//     Mint& operator/=(const Mint &b) {*this = *this / b;return *this;}
// };

// int factorial(int n){if(n <= 1) return 1; return factorial(n-1)*n;};
// int nCr(int n,int r){int num = factorial(n); int den1 = factorial(r); int de2 = factorial(n-r); return num/(den1*de2);}
// vector<ll> sieve(ll n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// ll mod_pow(ll base, ll power, int m){ll res=1;while(power){if(power&1){power = power-1;res = (res*base)%m;}else{power = power/2;base = (base*base)%m;}}return (res)%m;}
// ll miv_coprime(int a, int b){return mod_pow(a, b-2, b);}
// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
// ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, miv_coprime(b, m), m) + m) % m;}//only for prime m
// void Prime_Fact(ll n, vector<ll>&f){for(int x = 2; x*x <= n; x++) {while (n%x == 0) {f.push_back(x);n /= x;}}if (n > 1) f.push_back(n);}
// int extended_gcd(int a, int b, int &x, int &y){if(b == 0){x = 1;y = 0;return a;}int x0, y0;int g = extended_gcd(a, b, x0, y0);x = y0;y = x0 - (a/b)*y0;return g;}
// int sol_LDA(int a, int b, int c, int &x, int &y){int x0, y0;int g = extended_gcd(a, b, x0, y0);if(c % g){return 0;}x = x0 * c/g;y = y0 * c/g;if(a < 0) x = -x;if(b < 0) y = -y;return 1;}
// void All_Fact(int n, vector<int>&a){for(int i = 1; i*i<= n; i++){if(n % i == 0){a.push_back(i);if(n/i != i){a.push_back(n/i);}}}}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//templates
template<class T, class V>void _print(pair<T, V> p){cerr <<"["; _print(p.first); cerr <<" "; _print(p.second); cerr <<"]";}
template<class T> void _print(queue<T>q){cerr<< "["; while(!q.empty()){cerr << q.front() << " ";q.pop();}cerr<<" ]";}
template<class T> void _print(priority_queue<int, vector<int>, greater<int>>q){cerr<<"["; while(!q.empty()){cerr << q.top() << " ";q.pop();}cerr<<" ]";}
template<class T> void _print(vector<T> v){cerr << "[";for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v){cerr << "[";for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(unordered_set<T> v){cerr << "[";for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(map <T, V> m){cerr <<"{";for(auto i : m){_print(i) ; cerr <<" ";} cerr <<"}";}
template<class T> void _print(multiset <T> mst){cerr << "[";for(T i : mst){_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(vector<pair<T,V>>vp){for(auto i : vp){_print(i); cerr << "\n";}}
template<class T>void _print(vector<vector<T>> v) {cerr << "\n[\n";for (auto i : v) {cerr << "[";for (auto j : i) {_print(j);cerr << " ";}cerr << "]\n";}cerr << "]";}
template<class T>void _print(stack<T>st){cerr << "\n[\n";while(!st.empty()){cerr<< st.top() << " ";st.pop();}cerr << "]";}
template<class T> void _print(priority_queue<T>pq){cerr<< "\n[ ";while(!pq.empty()){_print(pq.top());pq.pop();}cerr << "]";}
template<class T, class V> void _print(map<T, vector<V>> mp){
	for(auto j:mp){
		cout << j.first <<"   [";
		for(int val:mp[j.first]){
			cerr << " "<< val << " ";
		}
		cout << " ]\n";
	}
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
