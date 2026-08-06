class Solution {
private:
    vector<vector<vector<int>>> dp;//{curr,m,n} - state , so no of subsets 
    int solve(int m , int n , vector<pair<int,int>>&count , int curr){
        if(curr < 0 || (m<=0 && n<=0)) return 0;

        if(dp[curr][m][n] != -1)return dp[curr][m][n];


        int take = 0;
        if(m >= count[curr].first && n>= count[curr].second) take = 1 + solve(m-count[curr].first , n-count[curr].second , count , curr -1);

        int not_take = solve(m,n,count,curr-1);
        return dp[curr][m][n] = max(take,not_take);

    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size() , vector<vector<int>>(m+1 , vector<int>(n+1 ,-1 )));
        vector<pair<int,int>>count;
        for(string s :strs){
            int zeroes=0;
            int ones =0;
            for(const char&ch : s){
                if(ch == '0') zeroes++;
                else ones++;
            }
            count.push_back({zeroes , ones});
        }

        return solve(m,n,count,strs.size()-1);


    }
};