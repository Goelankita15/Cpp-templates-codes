class LCA {
    vector<vector<int>> up; // up[i][j]: 2^j-th ancestor of node i
    vector<int> depth;      // depth[i]: depth of node i
    int LOG;

public:
    LCA(int n) {
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);
    }

    void dfs(int node, int parent, const vector<vector<int>>& adj) {
        up[node][0] = parent; // Direct parent
        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }
        for (auto& child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node, adj);
            }
        }
    }

    void preprocess(int root, const vector<vector<int>>& adj) {
        dfs(root, -1, adj);
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring u and v to the same depth
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        // Binary lift both nodes until their ancestors are the same
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0]; // The parent of u (or v) is the LCA
    }
};