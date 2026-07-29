class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long total_diff =0;
        int n = nums1.size();

        //case k =0-
        if(k==0){
            for(int i=0;i<n;i++){
                if(nums1[i] != nums2[i]) return -1;
            }
            return 0;
        }



        vector<long long> helper(n);
        long long  ops=0;
        for(int i=0;i<n;i++){
            long long diff = nums1[i]-nums2[i];
            if(abs(diff) % k != 0) return -1;
            total_diff += diff;
            helper[i] = diff;
            if(diff<0) ops += abs(diff)/k;
        }

        if(total_diff != 0) return -1;
        return ops;

        
    }
};