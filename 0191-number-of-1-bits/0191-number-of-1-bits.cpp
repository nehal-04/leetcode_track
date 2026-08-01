class Solution {
public:
    int hammingWeight(int n) {
        long long cur_value =1 ;
        int checker=1;
        int shifter =0;
        int ans=0;
        while (cur_value <= n){
            checker = 1<<shifter;
            if((checker & n) > 0) ans++;
            shifter ++;
            cur_value *= 2;
        }
        return ans;
        
    }
};