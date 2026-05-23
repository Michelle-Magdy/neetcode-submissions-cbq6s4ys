class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int ans = 0;
       const int ROWS = grid.size();
       const int COLS = grid[0].size();
       if(ROWS == 0) return 0;

       for(int i=0;i<ROWS;i++){
        for(int j = 0;j<COLS;j++){
            if(grid[i][j] == 1){
                ans = max(ans,dfs(grid ,i,j));
            }
        }
       } 
       return ans;
    }
    int dfs(vector<vector<int>>& grid, int r,int c){
        if(r<0 || c <0 ||r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        int res =1;
        grid[r][c] =0;
        for(int i =0;i<4;i++){
           res +=  dfs(grid,r+directions[i][0],c+directions[i][1]);
        }

        return res;
    }
};
