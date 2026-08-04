class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int final_ans=0;
        // use bx<=ay
        int n = nums.size();
        for(int i=0;i<n;i++){
            int odd_ct=0;
            int even_ct=0;
            for(int j=i;j<n;j++){
                if(nums[j] % 2 == 0) even_ct++;
                else odd_ct++;
                if(odd_ct > 0 && b * even_ct <= a*odd_ct) final_ans++;
            }
        }
        return final_ans;
        
    }
};