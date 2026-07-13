class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        vector<int>base(n+1 , 1);
        base[0]=0;
        base[n]=2;
        //total_sum is n+1, and elementsa in nuums should also be n+1
        if(nums.size() != n+1) return false;
        for(int x:nums){
            base[x]--;
        }
        int min_el = *min_element(base.begin() , base.end());
        int max_el = *max_element(base.begin() , base.end());
        if(max_el ==0 && min_el ==0) return true;
        return false;

    }
};