// CSES
// ankitagoel12 —  
// Shared code
// Link to this code: https://cses.fi/paste/9d08a0bf99eb080e9219d9/
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo-debugfile.cpp"
#else
#define dbg(x)
#endif
 
#define int long long
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define in(arr) for(int i =0; i<n; i++)cin>>(arr)[i];
#define print(a) for(int i =0; i<(a).size(); i++){ cout << (a)[i] <<" ";} cout << "\n";
typedef long long ll;
 
void solve(){
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> adj(n+1);
   for(int i = 0; i < m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
   }
 
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, 1});
   vector<int> vis(n+1, 0);
   vector<int> dist(n+1, 1e18);
   dist[1] = 0;
   
   while(!pq.empty()){
      int node = pq.top().second;
      int len = pq.top().first;
      pq.pop();
      
      if(vis[node]) continue;
      vis[node] = 1;
 
      for(auto &edge: adj[node]){
         int next_node = edge.first;
         int weight = edge.second;
         if(!vis[next_node] && dist[next_node] > dist[node] + weight){
            dist[next_node] = dist[node] + weight;
            pq.push({dist[next_node], next_node});
         }
      }
   }
 
   for(int i = 1; i <= n; i++){
      cout << dist[i] << " " ;
   }
   cout << "\n";
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