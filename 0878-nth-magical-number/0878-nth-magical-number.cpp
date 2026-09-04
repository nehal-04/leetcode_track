class Solution {
private:
    long long findlcm(int x , int y){
        return (1LL * x * y / gcd(x,y));
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l= 1;
        long long h = 1LL * n * min(a,b);
        int ans = h;
        int mod = 1e9 + 7;
        while(l<=h){
            long long mid =  l + (h-l)/2;
            // magical numbers b4 x -> (x/a) + (x/b) - (x/lcm(a,b))
            long long magical_numbers = (mid/a) + (mid/b) - (mid/findlcm(a,b)); 
            if(magical_numbers < n) l = mid +1 ;
            else{
                ans = (mid)%mod;
                h=mid-1;
            }
        }
        return ans;
    }
};