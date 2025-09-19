// CSES
// ankitagoel12 —  
// Shared code
// Link to this code: https://cses.fi/paste/342bd15306753fcb92a688/


//instack to keep the ancestors of a node such that we can determine the cylcle in the graph
//if the backedge is present then only the cycle is present in the directed graph otherwise not
//for example   1 --> 2 ------> 3 ---> 4
//                    .--> 5...^

// dfs(1) -> dfs(2) -> dfs(3) -> dfs(4) ===== instack = {1, 2,3, 4};
//dfs(1) -> dfs(2) -> dfs(3) ===== instack = {1, 2,3};
//dfs(1) -> dfs(2) -> dfs(5) -> dfs(3) == instack ={1, 2, 5};
// 3 is visited but not an ancestor of node 2 so it is not a back edge it is some other edge
//hence backtracing is neccassry
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
 
 
void solve(){
   int n, m ;
   cin >> n >> m;
   vector<vector<int>>adj(n+1);
   for(int i =0; i<m; i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
   }
 
   vector<int>vis(n+1, 0);
   vector<int>inStack(n+1, 0);
   vector<int>par(n+1);
   bool cycle = false;
   int start = -1;
   function<void(int)>dfs = [&](int u){
      vis[u] = 1;
      inStack[u] = true;
      for(auto i:adj[u]){
         if(vis[i]){
            if(inStack[i] == true){
               cycle = true;
               if(start == -1) start = u;
               par[i] = u;
            }
         }else{
            par[i] = u;
            dfs(i);
         }
      }
      inStack[u] = false;
   };
 
   vis.resize(n+1, 0);
   for(int i = 1; i<=n; i++){
      if(!vis[i]) dfs(i);
   }
   dfs(1);
   if(!cycle){
      cout << "IMPOSSIBLE\n";
      return;
   }
 
   vector<int>f(100006, 0);
   vector<int>ans;
   while(f[start] != 2 && start > 0){
      f[start]++;
      ans.push_back(start);
      if(f[start] == 2){
         break;
      }
      start = par[start];
   }
 
   vector<int>sol;
   sol.push_back(start);
   for(int i = ans.size()-2; i>=0; i--){
      if(ans[i] == start) break;
      sol.push_back(ans[i]);
   }
   sol.push_back(start);
   cout << sol.size() << "\n";
   print(sol)
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