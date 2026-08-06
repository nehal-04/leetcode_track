class Solution {
private:
    int productofdigits(int n){
        int ans =1;
        while(n>0){
            int d=n%10;
            ans*=d;
            n=n/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        int i=n;

        while(i<=n+10){
            int prod = productofdigits(i);
            if(prod % t == 0) return i;
            i++;
        }
        return -1;
        
    }
};