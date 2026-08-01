class Solution {
public:
    int hammingWeight(int n) {
        int ans =0;
        while(n>0){
            int d=n%2;
            if(d==1) ans++;
            n=n/2;
        }
        return ans;
        
    }
};