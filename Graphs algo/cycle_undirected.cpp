// CSES
// ankitagoel12 —  
// Shared code
// Link to this code: https://cses.fi/paste/03e964372efa0acea29f2c/
#include <bits/stdc++.h>
using namespace std;
 
#include<ext/pb_ds/assoc_container.hpp> //pbds
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
 
int mod = 1e9+7;
 
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_pow(int base, int power, int m){int res=1;while(power){if(power&1){power = power-1;res = (res*base)%m;}else{power = power/2;base = (base*base)%m;}}return (res)%m;}
void All_Fact(int n, vector<int>&a){for(int i = 1; i*i<= n; i++){if(n % i == 0){a.push_back(i);if(n/i != i){a.push_back(n/i);}}}}
 
void solve(){
   int n, m; cin >> n >> m;
   vector<vector<int>>adj(n+1);
   for(int i =0; i<m; i++){
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   vector<int>visited(n+1);
   bool has_cycle = false;
   vector<int>par(n+1, -1);
   int start_node = -1;
   function<void(int, int)> cycle = [&](int node, int parent){
      visited[node] = 1;
      for(int j: adj[node]){
         if(!visited[j]){
            par[j] = node;
            cycle(j, node);
         }else{
            if(j != parent && !has_cycle){
               has_cycle = true;
               start_node = j;
               par[j] = node;
            }
         }
      }
   };
 
   for(int i = 1; i<=n; i++){
      if(!visited[i]) cycle(i, -1);
   }
   if(has_cycle){
      vector<int>ans;
      int initial = start_node;
      ans.push_back(start_node);
      start_node = par[start_node];
      while(initial != start_node){
         ans.push_back(start_node);
         start_node = par[start_node];
      }
      ans.push_back(initial);
      cout << ans.size() << "\n";
      for(int i =0; i<ans.size(); i++){
         cout << ans[i] << " ";
      }
      cout << "\n";
   }else{
      cout << "IMPOSSIBLE\n";
   }
}  
 
int32_t main() {
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
   int Testcase = 1;
   //cin >> Testcase;
   for (int i = 0; i < Testcase; i++) {
      solve();
   }
   return 0;
}
/*
   set <-> multiset alert.
   Binary search.
   games -> find best possible moves in case of Alice and Bob win seperately.
   rotaion -> repeat.
*/