class Solution {
    void dfs(int node ,int parent , vector<int>& vis,vector<vector<int>>& adj){
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++){
            int neighbor = adj[node][i];
            if(neighbor != parent && vis[neighbor] == 0) {
            dfs(neighbor,node,vis,adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> vis(n,0);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans =0;
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){

            dfs(i,-1,vis,adj);
            ans++;
            }
        }
        return ans;
    }
};
