class Solution {
private:
    vector<int>dp; // { mask , cur_val }
    bool solve(int cur_value , int bit_mask , int desiredTotal , int maxChoosableInteger){
        
        if(dp[bit_mask] != -1 ) return (dp[bit_mask] == 0) ? false : true ;

        for(int i=1;i<=maxChoosableInteger;i++){
            //check if already used
            if((bit_mask & 1<<(i - 1)) > 0) continue;
            //now unused bit/number
            
            int new_b_mask = bit_mask | (1<<(i-1));
            if(cur_value + i >= desiredTotal) return dp[bit_mask] = true; 
            bool ans = solve(cur_value + i , new_b_mask , desiredTotal , maxChoosableInteger);
            if(ans == false) return dp[bit_mask] = true;            
        }
        return dp[bit_mask] = false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // as 20 size of max choosable integer
        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (total < desiredTotal) return false;
        dp.resize(1<<(maxChoosableInteger ) ,-1);
        return solve(0,0,desiredTotal,maxChoosableInteger);

    }
};