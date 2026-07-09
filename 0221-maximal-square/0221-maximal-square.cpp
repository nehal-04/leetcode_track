class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1));

        // BASE CASES   
        for(int i=0;i<=cols;i++) dp[0][i]=0;
        for(int i=1;i<=rows;i++) dp[i][0]=0;

        int maxans=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(matrix[i-1][j-1] == '0') {
                    dp[i][j] =0;
                    continue;
                }
                int top_sidelen = dp[i-1][j];
                int left_sidelen = dp[i][j-1];
                int diagonal_sidelen = dp[i-1][j-1];

                int minlen= min({top_sidelen , left_sidelen , diagonal_sidelen});
                dp[i][j] = minlen+1;
                maxans= max(maxans , dp[i][j]);

            }
        }
        return maxans * maxans;

    }
};