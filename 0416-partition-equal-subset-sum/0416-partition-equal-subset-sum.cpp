class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int s=0;
        for(int x:nums) s+=x;
        if(s%2 != 0) return false;
        s=s/2;
        //now one subset sum is this next's is automatically the value left
        vector<vector<bool>> dp (n+1 , vector<bool>(s+1));
        dp[0][0]=true;
        for(int i=1;i<=s;i++){
            dp[0][i]=false;
        }

        for(int i=1;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(j-nums[i-1] >=0)dp[i][j] = dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];


        
    }
};