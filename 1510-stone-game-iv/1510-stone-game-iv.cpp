class Solution {
public:
    bool winnerSquareGame(int n) {

        // if wse go bottom up dp 
        vector<int>dp(n+1 , true);
        int cur_ctr=1;
        dp[0]=false;
        for(int i=1;i<n+1;i++){
            if((cur_ctr+1) * (cur_ctr + 1) <= i) cur_ctr++;
            bool check = true;
            for(int j=1;j<=cur_ctr;j++){
                if(dp[i - j*j] == false) {
                    dp[i]=true;
                    check=false;
                    break;
                }
            }
            if(check) dp[i]=false;
        }
        return dp[n];
        
    }
};