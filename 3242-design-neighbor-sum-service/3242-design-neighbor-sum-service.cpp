class NeighborSum {
public:
    unordered_map<int,pair<int,int>> num_coord;
    vector<vector<int>>grid;
    int size;
    NeighborSum(vector<vector<int>>& grid_g) {
        int n=grid_g.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                num_coord[grid_g[i][j]] ={i,j};
            }
        }
        size=n;
        grid = grid_g;

    }
    
    int adjacentSum(int value) {
        int currow= num_coord[value].first;
        int curcol = num_coord[value].second;
        int ans=0;
        
        if(currow-1>=0) ans += grid[currow-1][curcol];
        if(currow + 1 <=size-1) ans += grid[currow+1][curcol];

        if(curcol-1>=0) ans += grid[currow][curcol-1];
        if(curcol + 1<=size-1) ans += grid[currow][curcol + 1];
        return ans;
        
    }
    
    int diagonalSum(int value) {
        int currow= num_coord[value].first;
        int curcol = num_coord[value].second;
        int ans=0;
        
        if(currow-1>=0 && curcol-1>=0) ans += grid[currow-1][curcol-1];
        if(currow -1 >= 0 && curcol+1 <= size-1) ans += grid[currow-1][curcol+1];

        if(currow + 1 <=size -1 && curcol-1>=0) ans += grid[currow+1][curcol-1];
        if(currow + 1 <=size-1 && curcol + 1<=size-1) ans += grid[currow+1][curcol + 1];
        return ans;

        
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */