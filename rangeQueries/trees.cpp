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
vector<int>segTree(600005);
vector<int>lazy(600005);
int ans = 0;
void build(vector<int>&a, int s, int e, int i){
   if(s == e){
      segTree[i] = a[e];
      return;
   }

   int mid = (s+e)/2;
   build(a, s, mid, 2*i);
   build(a, mid+1, e, 2*i+1);
   segTree[i] = segTree[2*i]+ segTree[2*i+1];
}

void update(int s, int e, int i,int a, int b, int val){
   // a s e b -> complete overlap
   if(a <= s && e <= b){
      lazy[i] += val;
      return;
   }

   // a b s e -> no overlap
   if(b < s or a > e){
      return ;
   }

   // partial overlap
   int mid = (s+e)/2;
   update(s, mid, 2*i, a, b, val);
   update(mid+1, e, 2*i+1, a, b, val);
   return;
}

void getElement(int s,int e, int i, int pos, int n){
   if(lazy[i] != 0 && i*2+1 <= 2*n){
      lazy[2*i] += lazy[i];
      lazy[2*i+1] += lazy[i];
      lazy[i] = 0;
   }
   dbg(i) dbg(lazy[i]) dbg(s) dbg(e)
   if(s == e){
      ans = segTree[i] + lazy[i];
      return ;
   }
   int mid =(s+e)/2;
   if(pos <= mid){
      getElement(s, mid, 2*i, pos, n);
   }else{
      getElement(mid+1,e, 2*i+1, pos, n);
   }

}
void solve(){
   int n, q;
   cin >>n >> q;
   vector<int>a(n+1);
   for(int i =1; i<=n; i++){
      cin >> a[i];
   }
   while((n&(n-1)) != 0){
      n++;
   }
   build(a, 1, n, 1);
   for(int i =0; i<q; i++){
      int type;
      cin >> type;
      if(type == 1){
         int l, r, val;
         cin >> l >> r >>val;
         update(1, n, 1, l, r, val);
      }else{
         int pos;
         cin >> pos;
         getElement(1, n, 1, pos, n);
         cout << ans << "\n";
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




