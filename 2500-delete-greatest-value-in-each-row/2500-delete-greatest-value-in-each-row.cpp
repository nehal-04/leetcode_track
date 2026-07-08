class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>>visited(r , vector<bool>(c,false));
        int ans = 0;
        int ctr=c;
        while(ctr>0){
            int max_for_iter=0;
            for(int i=0;i<r;i++){
                int per_row_max=0;
                int per_row_max_idx=-1;
                for(int j=0;j<c;j++){
                    if(visited[i][j]== true) continue;
                    if(grid[i][j] > per_row_max){
                        per_row_max = grid[i][j];
                        per_row_max_idx = j;
                    }
                }
                visited[i][per_row_max_idx] = true;
                max_for_iter = max(max_for_iter , per_row_max);
            }
            ans += max_for_iter;
            ctr--;
        }
        return ans;


    }
};