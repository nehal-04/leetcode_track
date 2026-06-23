class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows= obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0] ==1) return 0;

        vector<vector<int>>uniquepaths(rows , vector<int>(cols));
        uniquepaths[0][0]=1;
        for(int i=1;i<cols;i++){
            if(obstacleGrid[0][i] == 1) uniquepaths[0][i]=0;
            else uniquepaths[0][i] = uniquepaths[0][i-1];
        }

        for(int i=1;i<rows;i++){
            if(obstacleGrid[i][0] ==1) uniquepaths[i][0]=0;
            else uniquepaths[i][0] = uniquepaths[i-1][0];

        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j] ==1) uniquepaths[i][j]=0;
                else uniquepaths[i][j] = uniquepaths[i-1][j] + uniquepaths[i][j-1];
            }
        }
        return uniquepaths[rows-1][cols-1];
    }
};