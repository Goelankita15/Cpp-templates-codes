//finds the following:-
/*

 1. minimum distacnce front source to sink;
 2. Number of the minimum distances fron the source to sink
 3. minimum number of nodes in that shortest distance
 4. maximum number of nodes in that shortest distance
*/
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo-debugfile.cpp"
#else
#define dbg(x)
#endif
 
#define mod 1000000007
#define INF 1e18
#define int long long
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define in(arr) for(int i =0; i<n; i++)cin>>(arr)[i];
#define print(a) for(int i =0; i<(a).size(); i++){ cout << (a)[i] <<" ";} cout << "\n";
typedef long long ll;
 
void dijkstra(int s, vector<vector<pair<int, int>>>&adj, vector<int>&dist, vector<int>&routes, vector<int>&maxR, vector<int>&minR){
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
   dist[s] = 0;
   pq.push({0, s});
   vector<int>vis(adj.size(), 0);
   routes[s] = 1;
   while(!pq.empty()){
      int u = pq.top().S;
      int c = pq.top().F;
      pq.pop();
 
      if(vis[u] == 1) continue;
      vis[u] = 1;
 
      for(auto &edge: adj[u]){
         int v = edge.F;
         int d = edge.S;
         if(c+d < dist[v]){
            routes[v] = routes[u];
            dist[v] = c+d;
            maxR[v] = maxR[u]+1;
            minR[v] = minR[u]+1;
            pq.push({dist[v], v});
         }else if(c+d == dist[v]){
            routes[v] = (routes[u]+routes[v]) % mod;
            maxR[v] = max(maxR[v], maxR[u]+1);
            minR[v] = min(minR[v], minR[u]+1);
         }
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
 
   vector<int>dist(n+1, INF);
   vector<int>NumMinDisRoutes(n+1, 0), MinDisMinNodes(n+1, 0), MinDisMaxNodes(n+1, 0);
   dijkstra(1, adj,dist,NumMinDisRoutes, MinDisMaxNodes, MinDisMinNodes);
   cout << dist[n] << " " << NumMinDisRoutes[n] << " " << MinDisMinNodes[n] << " " << MinDisMaxNodes[n] << "\n";
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