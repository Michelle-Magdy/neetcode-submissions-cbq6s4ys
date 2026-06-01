class Solution {
    /**
     * @param {character[][]} board
     * @return {void} Do not return anything, modify board in-place instead.
     */
    solve(board: string[][]): void {
        const ROWS:number = board.length;
        const COLS:number = board[0].length;
        const visited: boolean[][] = Array.from({length:ROWS},()=>Array.from({length:COLS},()=>false));
        interface Point{
            x:number;
            y:number;
        }
        const q:Point[]=[];
        const dirs:number[][] =[
            [1,0],
            [-1,0],
            [0,1],
            [0,-1]
        ];


        for(let r = 0;r < ROWS;r++){
            for(let c =0;c<COLS;c++){
                if(board[r][c] === 'O' && !visited[r][c]){
                    const points:Point[] = [];
                    q.push({x:r,y:c});
                    let surr = true;
                    while(q.length !== 0){
                        const front:Point = q.shift();
                        visited[front.x][front.y] = true;
                        if(front.x === 0 || front.x === ROWS -1 || front.y === 0 || front.y === COLS-1){
                            surr =false;
                        }
                        
                        points.push({x:front.x,y:front.y});
                        for(const d of dirs){
                            const nr = front.x + d[0];
                            const nc = front.y + d[1];
                            if(nr >=0 && nr < ROWS && nc >=0 && nc < COLS && board[nr][nc] === 'O' && !visited[nr][nc]){
                                q.push({x:nr,y:nc});
                            }
                        }
                    }
                    if(surr){
                        for(const point of points){
                            board[point.x][point.y] = 'X';
                        }
                    }
                }
            }
        }


    }
}
