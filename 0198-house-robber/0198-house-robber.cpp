class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxamountusingi(n+1);
        vector<int>maxamountwithoutusingi(n+1);
        maxamountusingi[0]=0;
        maxamountwithoutusingi[0]=0;
        maxamountusingi[1]=nums[0];
        maxamountwithoutusingi[1]=0;

        for(int i=2;i<=n;i++){
            maxamountusingi[i]=max(nums[i-1]+maxamountusingi[i-2] , nums[i-1] + maxamountwithoutusingi[i-1]);
            maxamountwithoutusingi[i]= max(maxamountusingi[i-1] , maxamountwithoutusingi[i-1]); 
        }

        return max(maxamountusingi[n] , maxamountwithoutusingi[n]);
    }
};