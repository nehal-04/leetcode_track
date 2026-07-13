class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long ans=0;
        int l=0;
        int n=nums.size();
        int r=0;
        unordered_map<int,int> mp;
        int cur_c=0;
        while(l<=r && r<n){
            int val = nums[r];
            if(mp.count(val)!=0){
                cur_c += mp[val];
                mp[val] ++;
            }
            else{
                mp[val]++;
            }

            while(cur_c >=k){
                int first_val = nums[l];
                mp[first_val]--;
                cur_c -= mp[first_val];
                if(mp[first_val]==0) mp.erase(first_val);
                l++;
            }

            ans +=l;
            r++;
        }
        return ans;
        
    }
};