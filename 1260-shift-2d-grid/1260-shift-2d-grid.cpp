class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols = grid[0].size();

        int total=rows*cols;
        int eff_k = k % total;

        vector<vector<int>>finalans(rows , vector<int>(cols));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int oldidx = i*cols + j;

                int newidx = (oldidx + eff_k) % total;
                int new_r = newidx/cols;
                int new_c = newidx % cols;

                finalans[new_r][new_c] = grid[i][j];
            }
        }
        return finalans;

        
    }
};