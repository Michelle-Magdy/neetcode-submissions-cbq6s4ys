class Solution {

    bool dfs(int node ,int parent , vector<int>& vis,vector<vector<int>>& adj){
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++){
            int neighbor = adj[node][i];
            if((vis[neighbor] == 1 && neighbor != parent) || 
                (vis[neighbor] == 0 && dfs(neighbor,node,vis,adj))
            )
            return true;
        }
        vis[node] =2;
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> vis(n,0);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool ans = false;
        ans = !dfs(0,-1,vis,adj);
        for(int i=0;i<n;i++){
            if(vis[i] == 0) {
                ans = false;
                break;
            }
        }
        return ans;

    }
};
