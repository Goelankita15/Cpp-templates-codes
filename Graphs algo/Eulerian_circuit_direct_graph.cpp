/*
   EULER PATH -> either the Indeg = Outdeg for all the nodes 
                     OR
                 at most one node with (Outdeg-Indeg = 1) and at most one node with (Indeg - Outdeg = 1)

      start = node with this (Outdeg-Indeg = 1) , end = node with this (Indeg - Outdeg = 1)
   EULER CIRCUIT -> the Indeg = Outdeg for all the nodes 
      start , end -> any node can be choosen


   Code Implemented Below is for finding the euler circuit in a directed grap.
*/

#include <bits/stdc++.h>
using namespace std;
 
#include<ext/pb_ds/assoc_container.hpp> //pbds
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
// #ifndef ONLINE_JUDGE
// // #include "algo-debugfile.cpp"
// #else
// #define dbg(x)
// #endif
 
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
   vector<int>Indeg(n+1), Outdeg(n+1);
   for(int i =0; i<m; i++){
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      Outdeg[a]++;
      Indeg[b]++;
   }
   //for finding if all the nodes has even degree
   function<bool()>check1 = [&](){
      int start_node = 0 , end_node = 0;
      for(int i = 1; i<=n; i++){
         if((Indeg[i]-Outdeg[i]) > 1 or (Outdeg[i]-Indeg[i])> 1) return false;
         if((Indeg[i]-Outdeg[i]) == 1) end_node++;
         if((Outdeg[i]-Indeg[i]) == 1) start_node++;
      }
      if(start_node == 0 && end_node == 0) return true;
      if(start_node == 1 && end_node == 1) return true;
   };

   //for finding the graph is connected or not
   vector<int>vis(n+1, 0);
   function<void(int)>check2 = [&](int node){
      vis[node] = 1;
      for(int j:adj[node]){
         if(!vis[j]) check2(j);
      }
   }; check2(1);
   //finding the eularian cycle in the graph
   vector<int>route;
   function<void(int)>dfs = [&](int at){
      while (Outdeg[at] != 0) {
         int next = adj[at][--Outdeg[at]];
         dfs(next);
      }
      route.push_back(at);
   };

   //checking if the graph is connected or not
   int count = 0;
   for(int i = 1; i<=n; i++){
      if(!vis[i]){
         if(Indeg[i] > 0  or Outdeg[i] > 0){
            count = -1;
            break;
         }
      }
   }

   if(count == 0 && check1()){
      dfs(1);
      reverse(all(route));
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