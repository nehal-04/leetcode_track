class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> maxprofitafterfirstbuy(n);
        vector<int> maxprofitafterfirstsell(n);
        vector<int> maxprofitaftersecondbuy(n);
        vector<int> maxprofitaftersecondsell(n);

        maxprofitafterfirstbuy[0] = -prices[0];
        maxprofitafterfirstsell[0] =0;
        maxprofitaftersecondbuy[0] =INT_MIN; // vvimp 
        maxprofitaftersecondsell[0]=0;

        for(int i=1;i<n;i++){
            maxprofitafterfirstbuy[i] = max(maxprofitafterfirstbuy[i-1] , -prices[i]);
            maxprofitafterfirstsell[i] = max(maxprofitafterfirstsell[i-1] , maxprofitafterfirstbuy[i-1] + prices[i]);
            maxprofitaftersecondbuy[i] = max(maxprofitaftersecondbuy[i-1] , maxprofitafterfirstsell[i-1] -prices[i]);
            maxprofitaftersecondsell[i] = max(maxprofitaftersecondsell[i-1] , maxprofitaftersecondbuy[i-1] + prices[i]);
        }
        return max(maxprofitafterfirstsell[n-1] , maxprofitaftersecondsell[n-1]);


    }
};