class Solution {
private:
    void dfs(vector<vector<int>>&grid , int r , int c , vector<vector<int>>&visited , int &ans){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;

        if(grid[r][c] == 0 || visited[r][c]) return;
        visited[r][c]=1;
        ans += grid[r][c];
        dfs(grid , r+1 , c , visited , ans);
        dfs(grid , r-1 , c, visited , ans);
        dfs(grid , r , c+1 , visited ,ans);
        dfs(grid , r , c-1 , visited , ans);

    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>>q;//to store all initial posn to start
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] != 0) q.push({i,j});
            }
        }
        if(q.empty()) return 0;
        int finalans=INT_MIN;
        vector<vector<int>>visited(rows , vector<int>(cols , 0));
        while(!q.empty()){
            int r=q.front().first;
            int c = q.front().second;
            q.pop();
            int ans=0;
            dfs(grid , r , c , visited , ans);
            finalans=max(finalans , ans);
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++) visited[i][j] =0;
            }
        }
        return finalans;

        
    }
};