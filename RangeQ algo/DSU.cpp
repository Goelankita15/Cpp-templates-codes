class DSU{
public:
   vector<int>parent;
   vector<int>sizer, rank;

   DSU(int n = 0){
      parent.resize(n+1);
      sizer.resize(n+1, 1);
      rank.resize(n+1, 0);
      for(int i = 0; i<=n; i++){
         parent[i] = i;
      }
   }

   int findPar(int node){
      if(node == parent[node]){
         return node;
      }

      return parent[node] = findPar(parent[node]);
   }

   void unionBYSize(int u, int v){
      int uPar = findPar(u);
      int vPar = findPar(v);

      if(uPar == vPar) return;
      if(sizer[uPar] < sizer[vPar]){
         parent[uPar] = vPar;
         sizer[vPar] += sizer[uPar];
      }else{
         parent[vPar] = uPar;
         sizer[uPar] += sizer[vPar];
      }
      return;
   }

   void unionByRank(int u, int v){
      int uPar = findPar(u);
      int vPar = findPar(v);
      if(uPar == vPar) return;
      if(rank[uPar] < rank[vPar]){
         swap(uPar, vPar);
      }

      parent[vPar] = uPar;
      if(rank[uPar] == rank[vPar]){
         rank[vPar]++;
      }
      return;
   }
};
