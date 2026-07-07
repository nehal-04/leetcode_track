class Solution {
public:
    int minimumPossibleSum(int n, int target) {

        const long long MOD = 1e9 + 7;

        long long k = target / 2;

        if (n <= k)
            return (1LL * n * (n + 1) / 2) % MOD;

        long long s = (1LL * k * (k + 1) / 2) % MOD;

        long long rem = n - k;

        s = (s + (rem * (2LL * target + rem - 1) / 2) % MOD) % MOD;

        return s;
    }
};