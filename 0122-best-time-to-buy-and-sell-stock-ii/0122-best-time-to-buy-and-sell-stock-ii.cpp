class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp_atizerostock(n);
        vector<int>dp_ationestock(n);
        dp_atizerostock[0]=0;
        dp_ationestock[0] = -prices[0];

        for(int i=1; i<n;i++){
            dp_atizerostock[i] = max(dp_ationestock[i-1] + prices[i] , dp_atizerostock[i-1]);
            dp_ationestock[i] = max(dp_atizerostock[i-1] - prices[i] , dp_ationestock[i-1]);
        }

        return max(dp_atizerostock[n-1] , dp_ationestock[n-1]);          
    }
};