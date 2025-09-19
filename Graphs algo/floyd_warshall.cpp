// CSES
// ankitagoel12 —  
// Shared code
// Link to this code: https://cses.fi/paste/c38e8aae785f381da2bb97/
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
   int n, m, q; cin >> n >> m >> q;
   vector<vector<int>>dist(n+1, vector<int>(n+1, 1e18));
   for(int i =0; i<m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      dist[a][b] = min(dist[a][b], c);
      dist[b][a] = min(dist[b][a], c);
   }
   /*
   //failing = O[v^2log(v)+ q]

   function<void(int)>dijakstra = [&](int node){
      dist[node][node] = 0;
      set<pair<int, int>>s;
      vector<int>visited(n+1);
      s.insert({0, node});
      while(!s.empty()){
         int no = s.begin()-> second;
         int len = s.begin()-> first;
         s.erase(s.begin());
 
         if(visited[no]) continue;
         visited[no] = 1;
         for(auto j: adj[no]){
            int neigh = j.F;
            int wt = j.S;
            if(len + wt < dist[node][neigh]){
               if(dist[node][neigh] != 1e9){
                  s.erase({dist[node][neigh], neigh});
               }
               dist[node][neigh] = len + wt;
               s.insert({dist[node][neigh], neigh});
            }
         }
      }
   };
   for(int i = 1; i<=n; i++){
      dijakstra(i);
   }
   */
   
 
   //floyd warshal is faster O[n^3]
   for(int i = 1; i<=n; i++){
      for(int j = 1; j<=n; j++){
         if(i == j)dist[i][j] = 0;
      }
   }
 
   for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            if (dist[i][k] < 1e18 && dist[k][j] < 1e18) {
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
         }
      }
   }
   for(int i =0; i<q; i++){
      int u, v; cin >> u >> v;
      if(dist[u][v] ==1e18){
         cout << "-1\n";
      }else{
         cout << dist[u][v] << "\n";
      }
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