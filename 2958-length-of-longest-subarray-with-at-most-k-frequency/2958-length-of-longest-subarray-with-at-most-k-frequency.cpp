class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int l=0;
        int r = 0;
        int maxlen=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(l<r && mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            maxlen = max(r-l+1 , maxlen);
            r++;
        }
        return maxlen;
    }
};