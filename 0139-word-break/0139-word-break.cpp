class Solution {
private:
    
    vector<int>dp;

    bool helper(string s, unordered_set<string>&st , int curidx){
       
       int n = s.size();
       if(curidx >=n) return true;
       
       if(dp[curidx] != -1) return (dp[curidx] == 1) ? true : false;

       bool ans = false;
       
       for(int i=curidx;i<n;i++){
        if(st.find(s.substr(curidx , i-curidx+1)) != st.end()){
            bool sub_ans = helper(s , st , i+1);
            if(sub_ans == true) ans=sub_ans;
        }
       } 
       if(ans) return dp[curidx] = true;        
       return dp[curidx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        dp.resize(s.size() , -1); //-1- nevere visited , 0 false , 1 true    
        unordered_set<string>st;
        
        for(string x : wordDict){
            st.insert(x);
        }

        return helper(s,st,0);

    }
};