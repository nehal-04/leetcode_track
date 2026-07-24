class Solution {
private:
    long long helper(long long n){
    return (n*(n+1)/2);
    }

public:
    int countHomogenous(string s) {
        //curchar , curlen fromc curlen i can do 1+2..curlen the sum needed to be added
        
        int mod = 1e9 + 7;
        
        char curchar=s[0];
        int curlen=1;
        int total_ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i] == curchar) curlen++;
            else{
                total_ans = (total_ans + helper(curlen))%mod;
                curchar=s[i];
                curlen=1;
            }
        }

        total_ans = (total_ans + helper(curlen)) % mod;

        return total_ans;
        
    }
};