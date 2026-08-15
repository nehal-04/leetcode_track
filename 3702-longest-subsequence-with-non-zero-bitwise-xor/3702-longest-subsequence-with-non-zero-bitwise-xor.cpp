class Solution {

public:
    int longestSubsequence(vector<int>& nums) {
        // 1^2^3 =0 then both sides xor by either 1 or 2 or 3 and rhs becomes non zero , so if total xord is 0 and any one non -zero value exists rmove that and find non zero xor
        
        int n=nums.size();
        int cur_xor =0;
        int non_zero_ct=0;
        for(int x:nums){
            if(x!=0) non_zero_ct++;
            cur_xor ^= x;
        }

        if(cur_xor != 0) return n;
        if(non_zero_ct == 0) return 0;
        return n-1;
    }
};