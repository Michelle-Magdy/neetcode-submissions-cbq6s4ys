class Solution {
    bool isConnected(int source, int target, vector<int>& vis, vector<vector<int>>& adj) {
        if (source == target) return true;
        vis[source] = 1;
        
        for (int neighbor : adj[source]) {
            if (!vis[neighbor]) {
                if (isConnected(neighbor, target, vis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Reset visited array for every search
            vector<int> vis(n + 1, 0);
            
            // If u and v are already connected, this edge is redundant!
            if (isConnected(u, v, vis, adj)) {
                return edge;
            }
            
            // Otherwise, safely add the edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};