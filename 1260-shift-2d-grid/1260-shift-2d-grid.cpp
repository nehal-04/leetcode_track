class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols = grid[0].size();

        vector<int>flattenedout;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                flattenedout.push_back(grid[i][j]);
            }
        }
        //now essentially right rotate flattend out by k places
        int eff_k = k%(rows*cols);
        reverse(flattenedout.begin() , flattenedout.end());
        reverse(flattenedout.begin() , flattenedout.begin() + eff_k);
        reverse(flattenedout.begin() + eff_k , flattenedout.end());

        //now make array?
        vector<vector<int>>finalans;
        int cursize=0;
        vector<int>currow;
        for(int i=0;i<flattenedout.size() ; i++){
            cursize++;
            currow.push_back(flattenedout[i]);
            if(cursize == cols){
                finalans.push_back(currow);
                currow.clear();
                cursize=0;
            }
        }
        return finalans;

        
    }
};