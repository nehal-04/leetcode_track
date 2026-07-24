class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {

        //purely a dp question
        //based on hints , dp for each question store max points earnable if we started exam on that q
        int n=questions.size();
        vector<long long>dp(n);
        for(int i=n-1;i>=0;i--){
            long long skipq = (i+1 <=n-1)?dp[i+1]:0;
            long long takeq = ( i + questions[i][1] + 1  <= n-1)?dp[i+questions[i][1] + 1] + questions[i][0] : questions[i][0];
            dp[i] = max(skipq,takeq);   
        }
        return dp[0];
        
    }
};