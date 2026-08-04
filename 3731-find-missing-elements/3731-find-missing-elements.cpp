class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max_el = *max_element(nums.begin() , nums.end());
        int min_el = *min_element(nums.begin() , nums.end());

        vector<bool>ispresent(max_el-min_el+1 , false);
        for(int num:nums){
            ispresent[num-min_el] = true;
        }

        vector<int>ans;
        for(int i=0;i<ispresent.size();i++){
            if(ispresent[i] == false) ans.push_back(i + min_el);
        }
        return ans;
    }
};