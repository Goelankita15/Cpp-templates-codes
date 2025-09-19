/*
   EULER PATH -> exactly 0 or 2 nodes will be odd degree
      start = odd degree node, end = odd degree node
   EULER CIRCUIT -> all nodes must have even degree
      start , end -> any node can be choosen


   Code Implemented Below is for finding the euler circuit in an undirected grap.
*/

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
   vector<int>adj[n+1];
   vector<int>degree(n+1);
    map<pair<int, int>, int>cntEdges;
   for(int i =0; i<m; i++){
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      degree[a]++;
      degree[b]++;
      cntEdges[{a,b}]++;
      cntEdges[{b,a}]++;
   }
   //for finding if all the nodes has even degree
   function<bool()>check1 = [&](){
      for(int i = 1; i<=n; i++){
         if(degree[i] % 2) return false;
      }
      return true;
   };

   //for finding the graph is connected or not
   vector<int>vis(n+1, 0);
   function<void(int)>check2 = [&](int node){
      vis[node] = 1;
      for(int j:adj[node]){
         if(!vis[j]) check2(j);
      }
   }; check2(1);
   dbg(cntEdges)
   //finding the eularian cycle in the graph
   vector<int>route;
   function<void(int)>dfs = [&](int at){
      while(!adj[at].empty()){
         int next = adj[at].back();
         adj[at].pop_back();

         if(cntEdges[{at, next}] > 0){
            cntEdges[{at , next}]--;
            cntEdges[{next, at}]--;
            dfs(next);
         }
      }
      route.push_back(at);
   };

   //checking if the graph is connected or not
   int count = 0;
   for(int i = 1; i<=n; i++){
      if(!vis[i]){
         if(degree[i] > 0){
            count = -1;
            break;
         }
      }
   }

   if(count == 0 && check1()){
      dfs(1);
      dbg(cntEdges)
      for(int i =0; i<route.size(); i++){
         cout << route[i] << " ";
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
   // cin >> Testcase;
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