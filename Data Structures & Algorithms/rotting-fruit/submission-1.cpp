class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int m = grid.size();
        int n = grid[0].size();
        int nFresh = 0;

        queue<pair<int,int>> q;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] ==2){
                    q.push({i,j});
                }else if(grid[i][j]==1) nFresh++;
            }
        }
        if(nFresh == 0) return 0;
           vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};

        int ans= 0;
        while(!q.empty() && nFresh >0){
            int qSize =q.size();
            ans ++;
            for(int i =0;i<qSize;i++){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int d =0;d<4;d++){
                int r = row + dirs[d][0];
                int c = col + dirs[d][1];

                if (r < 0 || r >= m || c < 0 ||
                    c >= n || grid[r][c] != 1) {
                    continue;
                }
                grid[r][c] = 2;
                nFresh--;
                q.push({r,c});
            }

            }
        }

return nFresh == 0 ? ans:-1;
    
    }
};
