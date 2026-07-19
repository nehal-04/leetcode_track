class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        // LLLLL MMMM RRRRR this form of division present
        int r_tillnow=0;
        int m_tillnow=0;
        int mod =1e9 + 7;
        int ans =0;
        for(int x:nums){
            if(x<a){
                ans = (ans + r_tillnow + m_tillnow) % mod;
            }
            else if(x<=b){
                ans = (ans + r_tillnow)%mod;
                m_tillnow++;
            }
            else r_tillnow++;
        }
        return ans;
    }
};