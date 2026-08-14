class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin() , prices.end());
        sort(discounts.begin() , discounts.end());
        reverse(prices.begin() , prices.end());
        reverse(discounts.begin() , discounts.end());
        int n1 = prices.size();
        int n2 = discounts.size();

        double ans =0;
        int min_size = min(n1,n2);
        int ctr=0;

        while(ctr < min_size){
            int init_price = prices[ctr];
            int disc = discounts[ctr];
            double final_price = init_price * (100-disc) / 100.0;
            ans += final_price;
            ctr++;
        }
        while(ctr<n1) {
            ans += prices[ctr];
            ctr++;
        }
        return ans;
    }
};