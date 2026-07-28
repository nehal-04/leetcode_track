class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = {nums[i] , 0};
        }

        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j=i+k-1;
                dp[i][j].first = max(nums[i] + dp[i+1][j].second , nums[j] + dp[i][j-1].second);

                if(dp[i][j].first == nums[i] + dp[i+1][j].second ) dp[i][j].second = dp[i+1][j].first;
                else dp[i][j].second = dp[i][j-1].first;
            }
        }

        int p1 = dp[0][n-1].first;
        int p2 = dp[0][n-1].second;

        return p1>=p2;
    }
};