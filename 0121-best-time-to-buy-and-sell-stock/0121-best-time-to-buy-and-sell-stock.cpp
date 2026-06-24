class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minpriceseensofar=prices[0];
        int profit = INT_MIN;
        for(int i=1;i<prices.size();i++){
            if(prices[i] > minpriceseensofar){
                profit = max(prices[i] - minpriceseensofar , profit);
            }
            else{
                minpriceseensofar=prices[i];
            }
        }
        return (profit != INT_MIN)?profit:0;
        
    }
};