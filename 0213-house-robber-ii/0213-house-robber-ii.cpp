class Solution {
private:
    int helper(vector<int>temp){
        int n=temp.size();
        int prev=temp[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take= prev2 + temp[i];
            int skip = prev;
            int curi = max(skip , take);

            prev2=prev;
            prev=curi;
        }
        return prev;

    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int>temp1 , temp2;
        for(int i=0;i<n;i++){
            if(i==0){
                temp1.push_back(nums[i]);
                continue;
            }
            if(i==n-1){
                temp2.push_back(nums[i]);
                continue;
            }
            temp1.push_back(nums[i]);
            temp2.push_back(nums[i]);
        }
        
        return max(helper(temp1) , helper(temp2));
    }
};