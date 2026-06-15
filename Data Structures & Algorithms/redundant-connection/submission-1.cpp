

class DSU{
    vector<int> parent;
    vector<int> ranks;
public:
    DSU(int n){
        parent.resize(n,0);
        ranks.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int node){
        if(parent[node] != node){
            return find(parent[node]);
        }
        return node;
    }

    bool unionNodes(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;

        if(ranks[rootX] < ranks[rootY]){
            parent[rootX]= rootY;
        }else if(ranks[rootX] > ranks[rootY]){

            parent[rootY]= rootX;
        }else{
            parent[rootY]= rootX;
            ranks[rootX]++;
        }
        return true;
    }

};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if(!dsu.unionNodes(u,v)){
                return edge;
            }
        }
        
        return {};
    }
};