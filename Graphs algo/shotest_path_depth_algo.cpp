vector<int> getPath(int src, int destination, vector<vector<int>> &adj) {
  int n = adj.size();
  auto bfs = [&](int src) {
    vector<int> depth(n, -1), parent(n, -1);
    queue<int> q;
    depth[src] = 0;
    q.push(src);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (depth[v] == -1) {
          depth[v] = depth[u] + 1;
          parent[v] = u;
          q.push(v);
        }
      }
    }
    return parent;
  };
  vector<int> parent = bfs(src), path;
  for (int node = destination; node != -1; node = parent[node]) path.push_back(node);
  reverse(path.begin(), path.end());
  return path;
}