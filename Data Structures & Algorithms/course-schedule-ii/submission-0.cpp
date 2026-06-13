class Solution {
    vector<int> res;
    bool dfs(int i,vector<int>& vis, vector<vector<int>>& adj){
        if(vis[i]== 1) return true;
        if(vis[i] == 2) return false;
        vis[i] = 1;

        for(int c:adj[i]){
            if(dfs(c,vis,adj)) return true;
        }
        vis[i] = 2;
        res.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        for(auto &v: prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,adj))
                    return {};
            }
        }

        // reverse(res.begin(),res.end());
        return res;

    }
};
