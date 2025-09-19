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
    int n, m; 
    cin >> n >> m;
    
    vector<int> coins(n+1);
    for(int i = 1; i <= n; i++) cin >> coins[i];
    
    vector<pair<int, int>> edges;
    vector<int> adj[n+1], radj[n+1];
    
    for(int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        edges.push_back({u, v});
    }
 
    // Toposort DFS
    vector<int> toposort;
    vector<int> used(n+1, 0);
    function<void(int)> dfs = [&](int node) {
        used[node] = 1;
        for(int j : adj[node]){
            if(!used[j]){
                dfs(j);
            }
        }
        toposort.push_back(node);
    };
    
    // Get the topological order
    for(int i = 1; i <= n; i++) if(!used[i]) dfs(i);
    reverse(all(toposort));
    
    // Backtrack DFS to get SCCs
    int color = 0;
    used.assign(n+1, 0);
    vector<int> comp(n+1, 0);
    vector<int> sumSCC;
    
    function<void(int)> backtrack = [&](int node) {
        used[node] = 1;
        comp[node] = color;
        sumSCC[color] += coins[node];
        for(int j : radj[node]){
            if(!used[j]){
                backtrack(j);
            }
        }
    };
 
    // Process all SCCs
    for(int i = 0; i < n; i++){
        if(!used[toposort[i]]){
            sumSCC.push_back(0);  // Start new component sum
            backtrack(toposort[i]);
            color++;
        }
    }
 
    // Now, build the DAG of SCCs
    vector<vector<int>> dag(color);
    vector<int> indegree(color, 0);
    
    for(auto j : edges){
        int cu = comp[j.F], cv = comp[j.S];
        if(cu != cv) {
            dag[cu].push_back(cv);
            indegree[cv]++;
        }
    }
    
    // DP on the DAG to calculate maximum coin sum
    vector<int> dp(color, 0);
    queue<int> q;
    
    for(int i = 0; i < color; i++){
        if(indegree[i] == 0){
            dp[i] = sumSCC[i];
            q.push(i);
        }
    }
    
    int answer = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : dag[u]){
            dp[v] = max(dp[v], dp[u] + sumSCC[v]);
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
        answer = max(answer, dp[u]);
    }
    
    cout << answer << "\n";
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int Testcase = 1;
    // cin >> Testcase;
    while (Testcase--) {
        solve();
    }
    return 0;
}