class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();

        vector<int>dp(n,1);

        // as given in testcase 2 that the words can be reordered
        sort(words.begin() , words.end() , [](string &a , string &b){
            return a.size() < b.size();
        });

        int max_ans=1;

        for(int i=0;i<n;i++){
            string newword=words[i];
            int s1=newword.size();
            for(int j=0;j<i;j++){
                string compword= words[j];
                int s2=compword.size();

                if((s2 + 1) != s1) continue;
                int p=0,q=0;
                while(p<s1){
                    if(q<s2 && newword[p] == compword[q]) q++;
                    p++;
                }
                if(q==s2){
                    if(dp[j] + 1 > dp[i]){
                        dp[i]=dp[j]+1;
                    }
                }

            }
            if(dp[i] > max_ans){
                max_ans=dp[i];
                
            }

        }
        return max_ans;
    }
};