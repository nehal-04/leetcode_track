class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>primes(n,1); // 1 indicate is prime , 0 indicate not prime
        primes[0]=0;
        primes[1]=0;
        int limit=sqrt(n);
        for(int i=2;i<=limit;i++){
            if(primes[i]==1){
                for(int j=2;i*j <n;j++){
                    primes[j*i]=0;
                }
            }
        }
        int ans=0;
        for(int x:primes){
            if(x==1) ans++;
        }
        return ans;
        
    }
};