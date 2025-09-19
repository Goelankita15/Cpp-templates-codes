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
   vector<int>adj[n+1], radj[n+1];
   for(int i =0; i<m; i++){
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      radj[b].push_back(a);
   }
 
   vector<int>tpsort;
   vector<int>vis(n+1, 0);
   function<void(int)> dfs = [&](int no){
      vis[no] = 1;
      for(int j: adj[no]){
         if(!vis[j]) dfs(j);
      }
      tpsort.push_back(no);
   }; 
   for(int i = 1; i<=n; i++){
      if(!vis[i]) dfs(i);
   }
   reverse(all(tpsort));
   dbg(tpsort)
   int color = 1;
   vector<int>visited(n+1, 0);
   vector<int>ans(n+1, 0);
   function<void(int)> checkReverse =[&](int node){
      visited[node] = 1;
      ans[node] = color; 
      for(int j: radj[node]){
         if(!visited[j]) checkReverse(j);
      }
   };
 
   for(int i =0; i<tpsort.size(); i++){
      if(!visited[tpsort[i]]){
         checkReverse(tpsort[i]);
         color++;
      }
   }
 
   cout << color-1 << "\n";
   for(int i =1; i<=n; i++){
      cout << ans[i] << " ";
   }
   cout << "\n";
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
