class Solution {
private:
    vector<int>dp; // -1 meaning not calculated yet 
    int helper(string& s , unordered_set<string>&st , int cur_idx){
        int n=s.size();
        if(cur_idx >= n) return 0;
        if(dp[cur_idx] != -1) return dp[cur_idx];
        
        int final_ans = n-cur_idx;
        for(string x:st){
            int sz = x.size();
            if(s.substr(cur_idx , sz) == x){
                final_ans = min(final_ans , helper(s,st,cur_idx+sz));
            }
        }
        if(final_ans == n-cur_idx) return dp[cur_idx] = 1 + helper(s,st,cur_idx + 1);
        return dp[cur_idx] = min(final_ans , 1+helper(s,st,cur_idx+1));
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        dp.resize(s.size() , -1);
        for(string x:dictionary){
            st.insert(x);
        }      
        return helper(s , st , 0);

    }
};