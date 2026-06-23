class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();

        //operatuioins done on word 1 so weord 1 coneverted to word 2 
        vector<vector<int>> dp(s1 + 1 , vector<int>(s2+1)); //dp -> operations required to convert first i chars of word 1 to first j characters of word 2
        dp[0][0]=0;
        for(int i=1;i<=s1;i++){
            dp[i][0] = i;
        }

        for(int i=1;i<=s2;i++){
            dp[0][i]=i;
        }

        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j-1] , dp[i][j-1] , dp[i-1][j]}) +1;

                }

            }
        }
        return dp[s1][s2];

    }
};