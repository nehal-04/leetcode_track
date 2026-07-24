class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int>st1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = nums[i] ^ nums[j];
                st1.insert(val);
            }
        }

        //now for the third elemnt
        unordered_set<int>st2;
        for(int p : st1){
            for(int i=0;i<n;i++){
                st2.insert(p ^ nums[i]);
            }
        }
        return st2.size();
        
    }
};