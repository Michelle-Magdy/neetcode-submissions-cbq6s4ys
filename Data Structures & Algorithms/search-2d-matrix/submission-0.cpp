class Solution {
public:
    bool can(int curr, int target){
        return curr <= target;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r = matrix.size() -1 ;
        int i =0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(can(matrix[mid][0],target)){
                i = mid;
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        
        l = 0;
        r = matrix[0].size() -1;
        bool found = false;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[i][mid] == target) {
                found =true;
                break;
            }
            else if(matrix[i][mid] < target) l = mid +1;
            else r = mid -1;
        }
        return found;
    }
};
