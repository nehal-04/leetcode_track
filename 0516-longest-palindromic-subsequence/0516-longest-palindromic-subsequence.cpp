class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //i and j logic maybe idk 
        int n=s.size();

        vector<vector<int>> dp(n, vector<int>(n));
        //dp[i][j] is longest palindromic subsequence within indexes i and j
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        for(int k=2;k<=n;k++){
            for(int i= 0 ;i<=n-k;i++){
                int j= i+k-1;
                if(s[i] == s[j]){
                    if(k==2) dp[i][j]=2;
                    else dp[i][j] = 2+dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j] , dp[i][j-1] );
                }
            }

        }
        return dp[0][n-1];

        
    }
};