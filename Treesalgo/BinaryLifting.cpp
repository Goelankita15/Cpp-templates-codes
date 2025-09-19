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
int mod = 1e9 + 7;
 
void dfs(int node, int parent, vector<vector<int>>&edges, vector<int>&depth){
   for(int edge: edges[node]){
      if(edge != parent){
         depth[edge] = depth[node]+1;
         dfs(edge, node, edges, depth);
      }
   }
}
void solve() {
   int n, q;
   cin >> n >> q;
   int limit = log2(n)+1;
   vector<vector<int>>parent(n+1, vector<int>(limit, 0)); 
   vector<vector<int>>edges(n+1);
   vector<int>depth(n+1);
   parent[1][0] = 0;
   for(int i =0; i<n-1; i++){
      int x;
      cin >> x;
      parent[i+2][0] = x; 
      edges[x].push_back(i+2);
      edges[i+2].push_back(x);
   }
   dfs(1, -1, edges, depth);
   
   // calculating parents preprocessing
   for(int i = 1; i< limit; i++){
      for(int j = 1; j<=n; j++){
         int x = parent[j][i-1];
         parent[j][i] = parent[x][i-1];
      }
   }
   
   //function for finding the kth parent of a given node by gouing upwards if thar bit is set in the node
   auto kthParent = [&](int node, int k){
      for(int i = 25; i>=0; i--){
         if(k & (1<<i)){
            node = parent[node][i];
            k -= (1<<i);
         }
      }
      return node;
   };
/*
   //recurssive way to find the kth parent of the node
   
   function <int(int, int)> kthParent = [&](int node, int k){
      if(k == 0){
         return node;
      }
      int msb = log2(k);
      int max_power = (1<<msb);
      return kthParent(parent[node][msb], k-max_power);
   }
*/    
   for(int i =0; i<q; i++){
      int node, k;
      cin >> node >> k;
      if(depth[node] < k){
         cout<<  -1 << "\n";
      }else{
         cout << kthParent(node, k) << "\n";
      }
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
}
