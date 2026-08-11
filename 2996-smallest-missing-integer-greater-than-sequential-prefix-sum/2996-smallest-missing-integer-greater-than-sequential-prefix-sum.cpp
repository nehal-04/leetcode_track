class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int l = 0;
        int r = 1;
        int n = nums.size();
        int start=0; 
        int maxlen = 1;
        while(r<n && nums[r-1] + 1 == nums[r]) r++;

        int ans =0;
        for(int i=0;i<r ;i++) ans += nums[i];

        unordered_set<int> st;
        for(int num:nums) st.insert(num);

        while(st.count(ans) > 0) ans ++;
        return ans;
        
    }

};