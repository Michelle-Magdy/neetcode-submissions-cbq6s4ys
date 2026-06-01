class Solution {
    /**
     * @param {number} numCourses
     * @param {number[][]} prerequisites
     * @return {boolean}
     */
    canFinish(numCourses: number, prerequisites: number[][]): boolean {
        const adj = new Map();
        for(let i=0;i<numCourses;i++){
            adj.set(i,[]);
        }

        for(let [crs,pre] of prerequisites){
            adj.get(crs).push(pre);
        }

        const visited = Array.from({length:numCourses +1},()=>false);
        const dfs= (crs)=>{
            if(visited[crs]) return false;
            visited[crs] = true;
            for(let child of adj.get(crs)){
                if(!dfs(child)) return false;
            }
            adj.set(crs,[]);
            visited[crs] = false;

            return true;
        }

        for(let i =0 ;i<numCourses;i++){
            if(!dfs(i)) return false;
        }
        return true;

    }
}
