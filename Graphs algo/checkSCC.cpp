#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo-debugfile.cpp"
#else
#define dbg(x)
#endif
 
 
#define mod 1000000007
#define inf 1e18
#define int long long
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define in(arr) for(int i = 0; i < n; i++) cin >> (arr)[i];
#define print(a) for(int i = 0; i < (a).size(); i++) { cout << (a)[i] << " "; } cout << "\n";
 
int m = 998244353;
void solve() {
   int n; cin >> n;
   vector<pair<int, int>>deg(n+1);
   vector<vector<int>>adj(n+1);
   for(int i =0; i<n-1; i++){
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      deg[u] = {u, deg[u].S+1};
      deg[v] = {v, deg[v].S+1};
   }
   dbg()
   int times = 2;
   while(times > 0){
      sort(all(deg));
      for(int j: )
   }
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
   int t = 1;
    // cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}