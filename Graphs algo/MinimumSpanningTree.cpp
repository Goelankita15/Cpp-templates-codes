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
class DisjointSet {
   vector<int> rank, parent, size;
public:
   DisjointSet(int n) {
      rank.resize(n + 1, 0);
      parent.resize(n + 1);
      size.resize(n + 1);
      for (int i = 0; i <= n; i++) {
         parent[i] = i;
         size[i] = 1;
      }
   }
 
   int findUPar(int node) {
      if (node == parent[node])
         return node;
      return parent[node] = findUPar(parent[node]);
   }
 
   void unionByRank(int u, int v) {
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);
      if (ulp_u == ulp_v) return;
      if (rank[ulp_u] < rank[ulp_v]) {
         parent[ulp_u] = ulp_v;
      }
      else if (rank[ulp_v] < rank[ulp_u]) {
         parent[ulp_v] = ulp_u;
      }
      else {
         parent[ulp_v] = ulp_u;
         rank[ulp_u]++;
      }
   }
 
   void unionBySize(int u, int v) {
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);
      if (ulp_u == ulp_v) return;
      if (size[ulp_u] < size[ulp_v]) {
         parent[ulp_u] = ulp_v;
         size[ulp_v] += size[ulp_u];
      }
      else {
         parent[ulp_v] = ulp_u;
         size[ulp_u] += size[ulp_v];
      }
   }
};
 
class Solution
{
public:
    int spanningTree(int V,vector<pair<int, pair<int, int>>>&edges)
   {
      DisjointSet ds(V);
      sort(edges.begin(), edges.end());
      int mstWt = 0;
      for (auto it : edges) {
         int wt = it.first;
         int u = it.second.first;
         int v = it.second.second;
 
         if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
         }
      }
 
     return mstWt;
   }
};
 
void check(int node, vector<int>& vis, vector<pair<int, int>> adj[]) {
   vis[node] = 1;
   for (auto j : adj[node]) {
      if (!vis[j.F]) {
         check(j.F, vis, adj);
      }
   }
}
void solve() {
   int n, m;
   cin >> n >> m;
   vector<pair<int, pair<int, int>>>adj;
   vector<pair<int, int>> adj2[n+1];
   for(int i =0; i<m; i++){
      int x, y, z;
      cin >> x >> y >> z;
      adj2[x].push_back({y, z});
      adj2[y].push_back({x, z});
      adj.push_back({z, {x, y}});
   }
   vector<int>vis(n+1,0);
   check(1, vis,adj2);
   if(accumulate(vis.begin(), vis.end(), 0) != n){
      cout << "IMPOSSIBLE\n";
      return;
   }
   Solution obj;
   int mstWt = obj.spanningTree(n, adj);
   cout << mstWt << "\n";
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
