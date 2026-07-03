class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int cur_zeroes=0;
        int maxwindow=0;
        while(r<nums.size()){
            if(nums[r]==0) cur_zeroes++;
            while(cur_zeroes>k && l<=r){
                if(nums[l] == 0){
                    cur_zeroes -=1;
                }
                l++;
            }
            maxwindow=max(maxwindow, r-l+1);
            r++;
        }
        return maxwindow;
    }
    
};