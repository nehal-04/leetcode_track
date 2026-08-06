class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total_sum=0;
        for(int x:nums) total_sum += x;

        // total sum = sum(p) + sum(n)   target = sum(p)-sum(n)

        if((total_sum + target) % 2 != 0) return 0;
        int fin = (total_sum + target) / 2;
        if(fin<0) return 0;

        vector<vector<int>> dp (n+1 , vector<int>(fin+1 )); // number of ways from first i elements to amek target (variable)

        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0] = (nums[i-1] == 0) ? 2* dp[i-1][0] : dp[i-1][0];
        }

        for(int i=1;i<=fin;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=fin;j++){
                int take =0;
                take = (nums[i-1] <=j)? dp[i-1][j-nums[i-1]] : 0;
                int not_take = dp[i-1][j];
                dp[i][j] = take +not_take;
            }
        }
        return dp[n][fin];

    }
};