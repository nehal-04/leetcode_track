class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int n=nums.size();
        int i=1;
        while(i<=n){
            i=i*2;
        }
        return i;

    }
};