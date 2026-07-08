class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        vector<int>ans;
        while(i<n){
            int pick1=nums[i];
            i++;
            int pick2=nums[i];
            i++;
            ans.push_back(pick2);
            ans.push_back(pick1);
        }
        return ans;
    }
};