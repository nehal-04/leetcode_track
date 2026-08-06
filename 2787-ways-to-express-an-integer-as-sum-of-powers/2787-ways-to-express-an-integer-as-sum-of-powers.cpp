class Solution {
public:
    int numberOfWays(int n, int x) {
        int mod = 1e9 + 7;

        int init=1;
        while(true){
            if(pow(init,x) > n) break;
            else init++;
        }
        init--;

        vector<vector<int>>dp(init+1 , vector<int>(n+1));
        // dp[i][j] = number of ways to make sum j using the first i numbers (1...i), where each number contributes its x-th power at most once.

        dp[0][0]=1;
        for(int i=1;i<=init;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=init;i++){
            for(int j=1;j<=n;j++){
                int take = 0;

                if(j-pow(i,x) >= 0 ) take = dp[i-1][j-pow(i,x)];
                int not_take = dp[i-1][j];
                dp[i][j]=(take + not_take) % mod;
            }
        }
        return dp[init][n];

    }
};