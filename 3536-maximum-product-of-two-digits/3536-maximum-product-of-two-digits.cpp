class Solution {
public:
    int maxProduct(int n) {
        int l_n=0;
        int sl_n=0;
        while(n>0){
            int d= n%10;
            if(d>l_n){
                sl_n=l_n;
                l_n=d;
            }
            else if(d<=l_n && d>sl_n){
                sl_n=d;
            }
            n=n/10;
        }
        return l_n * sl_n;
        
    }
};