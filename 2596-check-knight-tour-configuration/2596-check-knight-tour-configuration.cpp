class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {

       if(grid[0][0] != 0) return false; 
        
        int n = grid.size() ; //no of rows = no of cols
        vector<int>dr = {-2,-2,2,2 ,-1,-1,1,1};
        vector<int>dc = {1,-1,1,-1 ,2,-2,2,-2};
        int ctr=0;
        int cur_r=0;
        int cur_c=0;
        while(ctr < n*n  - 1){
            bool changed=false;
            int new_r , new_c;
            for(int i=0;i<8;i++){
                new_r = cur_r + dr[i];
                new_c = cur_c + dc[i];
                if(new_r < 0 || new_c <0 || new_r >=n || new_c >= n || grid[new_r][new_c]!=ctr+1) continue;
                changed = true;
                break;
            }
            if(changed){
                cur_r = new_r;
                cur_c=new_c;
                ctr++;
            }
            else return false;
        }
        return true;
    }
};