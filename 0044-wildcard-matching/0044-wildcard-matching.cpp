class Solution {
public:
    bool isMatch(string s, string p) {

        int s1=s.size();
        int s2=p.size();
        vector<vector<bool>> dp(s1+1 , vector<bool>(s2+1));

        dp[0][0]= true;
        for(int i=1;i<=s1;i++){
            dp[i][0] = false;
        }

        for(int i=1 ; i<=s2;i++){
            if(p[i-1] =='*') dp[0][i] = dp[0][i-1];
            else dp[0][i]=false;
        }

        // base done

        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if (p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1]; //* cna be empty too 
                else dp[i][j]=false;
            }
        }
        return dp[s1][s2];
    }
};