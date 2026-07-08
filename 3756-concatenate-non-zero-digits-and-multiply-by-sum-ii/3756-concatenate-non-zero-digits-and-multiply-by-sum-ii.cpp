#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int mod = 1e9 + 7;
        int sz = s.size();

        vector<int> prefix_sum(sz);
        vector<int> count_of_nonzero_numbers(sz);
        vector<int> concatenated_number(sz);
        vector<long long> powerof10(sz + 1);
        
        // 1. Correctly precompute powers of 10 with modulo
        powerof10[0] = 1;
        for (int i = 1; i <= sz; i++) {
            powerof10[i] = (powerof10[i - 1] * 10) % mod;
        }

        int running_sum = 0;
        int running_countofnonzeroes = 0;
        long long running_concatenatedno = 0;
        for (int i = 0; i < sz; i++) {
            int d = s[i] - '0';
            running_sum += d;
            prefix_sum[i] = running_sum;
            if (d == 0) {
                concatenated_number[i] = running_concatenatedno;
                count_of_nonzero_numbers[i] = running_countofnonzeroes;
                continue;
            }
            running_concatenatedno = (running_concatenatedno * 10 + d) % mod;
            running_countofnonzeroes++;
            concatenated_number[i] = running_concatenatedno;
            count_of_nonzero_numbers[i] = running_countofnonzeroes;
        }
        for (int i = 0; i < n; i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            long long sum_used = 0;
            long long number = 0;
            if (from == 0) {
                sum_used = prefix_sum[to];
                number = concatenated_number[to];
            } else {
                sum_used = prefix_sum[to] - prefix_sum[from - 1];
                int ct_ofnonzero = count_of_nonzero_numbers[to] - count_of_nonzero_numbers[from - 1];
                
                // 2. Prevent negative results using (+ mod) % mod
                long long remove_part = (1LL * concatenated_number[from - 1] * powerof10[ct_ofnonzero]) % mod;
                number = (concatenated_number[to] - remove_part + mod ) % mod;
            }

            ans[i] = (sum_used * number) % mod;
        }

        return ans;
    }
};