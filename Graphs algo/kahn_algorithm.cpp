#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> lexicographicallySmallestTopologicalOrder(int n, vector<vector<int>>& edges) {
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    
    // Build adjacency list and calculate indegrees
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Min-heap to store nodes with zero incoming edges
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Add all nodes with indegree 0 to the min-heap
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            minHeap.push(i);
        }
    }

    vector<int> topologicalOrder;

    // Process nodes in topological order
    while (!minHeap.empty()) {
        int u = minHeap.top();
        minHeap.pop();
        topologicalOrder.push_back(u);

        // Decrease the indegree of adjacent nodes
        for (int v : adj[u]) {
            indegree[v]--;
            // If indegree becomes 0, add to min-heap
            if (indegree[v] == 0) {
                minHeap.push(v);
            }
        }
    }

    // Check if topological sort is possible (i.e., no cycle)
    if (topologicalOrder.size() != n) {
        return {}; // Return empty vector if there is a cycle
    }

    return topologicalOrder;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> order = lexicographicallySmallestTopologicalOrder(n, edges);

    if (order.empty()) {
        cout << "Cycle detected. Topological ordering is not possible." << endl;
    } else {
        cout << "Lexicographically smallest topological order: ";
        for (int node : order) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
