class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        
        int j=n-1;
        int i=0;

        while(j>=i){
            if(nums[j]==val) j--;
            else break;
        }
        if(j<i) return 0;
        if(j==i) return 1;
        while(i<j){
            if(nums[i] == val){
                swap(nums[i],nums[j]);
                while(j>=i){
                    if(nums[j]==val) {j--;}
                    else break;
                }
                
                                
            }
            i++;
        }
        return j+1;
    }
    
};