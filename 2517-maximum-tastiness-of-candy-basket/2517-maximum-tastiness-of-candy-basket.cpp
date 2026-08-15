class Solution {
private:
    int helper(vector<int>&price , int k , int m){
        int cur_el = 1;
        int n = price.size();
        int last_el = price[0];
        for(int i=1;i<n;i++){
            if(price[i] - last_el >= m){
                cur_el++;
                last_el=price[i];
            }
            if(cur_el == k) return k; 
        }
        return cur_el;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        int max_p = *max_element(price.begin() , price.end());
        int min_p = *min_element(price.begin() , price.end());
        sort(price.begin(),price.end());
        
        //binary search 
        int l=0;
        int h  = max_p - min_p;
        int fin_ans = 0;
        while(l <= h){
            int m = l + (h-l)/2;
            int ans = helper(price , k ,m);
            if(ans == k){
                fin_ans = m;
                l=m+1;
            }
            else h = m-1;
        }
        return fin_ans;
    }
};