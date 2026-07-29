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
        for(int i=0;i<n;i++){
            long long diff = nums1[i]-nums2[i];
            if(abs(diff) % k != 0) return -1;
            total_diff += diff;
            helper[i] = diff;
        }

        if(total_diff != 0) return -1;

        sort(helper.begin() , helper.end());
        int i=0;
        int j = n-1;
        long long ops = 0;
        while(i<j){
            if(helper[i] == 0){
                i++;
                continue;
            }
            else if (helper[j] == 0){
                j--;
                continue;
            }
            else if(helper[i] >0 && helper[j] > 0 ) return -1;
            else if(helper[i] < 0 && helper[j] < 0) return -1;

            int take = min(-1*helper[i] , helper[j]);

            helper[i] += take;
            helper[j] -=take;
            ops += take/k;
            if(helper[i] == 0) i++;
            if(helper[j] == 0) j--; 
        }

        return ops;




        
    }
};