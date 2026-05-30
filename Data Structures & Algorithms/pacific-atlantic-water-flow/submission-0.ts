class Solution {
    /**
     * @param {number[][]} heights
     * @return {number[][]}
     */
    pacificAtlantic(heights: number[][]): number[][] {
        const ROWS = heights.length,
            COLS = heights[0].length;

        let pac = Array.from({length:ROWS},()=> Array(COLS).fill(false));
        let atl = Array.from({length:ROWS},()=> Array(COLS).fill(false));

        const dirs =[
            [1,0],
            [-1,0],
            [0,1],
            [0,-1]
        ]
        const valid = (r:number,c:number):boolean=>{
            return r >= 0 && r < ROWS && c >=0 && c < COLS;
        }
        const dfs = (r:number,c:number,ocean:boolean[][]) =>{
            if(!valid(r,c)|| ocean[r][c] === true) return;
            ocean[r][c] = true;
            for(let [dr,dc] of dirs){
                let nr = r + dr,
                    nc = c + dc;
                if(valid(nr,nc) && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    dfs(nr,nc,ocean);
                }
            }
        }
        for(let c = 0;c < COLS;c++){
            dfs(0,c,pac);
            dfs(ROWS-1,c,atl);
        }
        for(let r = 0;r < ROWS;r++){
            dfs(r,0,pac);
            dfs(r,COLS-1,atl);
        }
        let res:number[][] = [];
        for(let i=0;i<ROWS;i++){
            for(let j = 0;j<COLS;j++){
                if(atl[i][j] && pac[i][j]){
                    res.push([i,j]);
                }
            }
        }
        return res;
    }
}
