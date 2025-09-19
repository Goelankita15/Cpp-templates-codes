// CSES
// ankitagoel12 —  
// Shared code
// Link to this code: https://cses.fi/paste/ce5dedfd37b24d45923d23/
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo-debugfile.cpp"
#else
#define dbg(x)
#endif
 
#define INF 1e18
#define int long long
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define in(arr) for(int i =0; i<n; i++)cin>>(arr)[i];
#define print(a) for(int i =0; i<(a).size(); i++){ cout << (a)[i] <<" ";} cout << "\n";
typedef long long ll;
 
void dfs(int n, vector<int>&vis, vector<vector<pair<int, int>>>&adj){
   vis[n] = 1;
   for(auto i:adj[n]){
      if(!vis[i.F]){
         dfs(i.F, vis, adj);
      }
   }
}
void solve(){
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>>adj(n+1);
   for(int i =0; i<m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
   }
 
   vector<int>dist(n+1, -INF);
   dist[1] = 0;
   //Bellman ford
   for(int i = 1; i < n; i++){
      for(int u = 1; u <= n; u++){
         if(dist[u] == -INF) continue;
         for(auto edge : adj[u]){
            int v = edge.F;
            int weight = edge.S;
            if(dist[v] < dist[u] + weight){
               dist[v] = dist[u] + weight;
            }
         }
      }
   }
 
   //nth iteration for checking arbitrary large weight
   for(int u = 1; u <= n; u++){
      if(dist[u] == -INF) continue;
      for(auto edge : adj[u]){
         int v = edge.F;
         int weight = edge.S;
         if(dist[v] < dist[u] + weight){
            vector<int>vis(n+1, 0);
            dfs(v, vis, adj);
            if(vis[n]){
               cout << "-1\n";
               return;
            }
         }
      }
   }
 
   cout << dist[n] << "\n";
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
}