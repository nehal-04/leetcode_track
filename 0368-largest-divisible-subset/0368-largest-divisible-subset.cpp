class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1); // longesr such subset within first i elements endign at i , i.e the ith element to be aprt of the subset 

        sort(nums.begin() , nums.end());

        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int best_val=1;
        int idx_forbestval =0;
        for(int i=0;i<n;i++){
        
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0 && dp[i] < dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i] >best_val){
                best_val = dp[i];
                idx_forbestval = i;
            }
        }


        //reconstruction
        vector<int>lis;
        while(parent[idx_forbestval] != idx_forbestval){
            lis.push_back(nums[idx_forbestval]);
            idx_forbestval=parent[idx_forbestval];
        }
        lis.push_back(nums[idx_forbestval]);
        return lis;
    }

};