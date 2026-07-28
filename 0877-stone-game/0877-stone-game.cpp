class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = {piles[i] , 0};
        }
        //now from length k = 2 to total length i believe
        for(int k = 2; k <=n ; k++){
            for(int i = 0;i<=n-k;i++){
                int j = i + k -1;

                dp[i][j].first = max ( piles[i] + dp[i+1][j].second   ,  piles[j] + dp[i][j-1].second);

                if(dp[i][j].first == piles[i] + dp[i+1][j].second) dp[i][j].second = dp[i+1][j].first;
                else dp[i][j].second = dp[i][j-1].first;
            }
        }
        int alice = dp[0][n-1].first;
        int bob = dp[0][n-1].second;
        return alice > bob;
        
    }
};