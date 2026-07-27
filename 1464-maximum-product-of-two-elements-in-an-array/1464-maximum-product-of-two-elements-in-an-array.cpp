class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int largest=nums[0];
        int second_l = 0;
        for(int i=1;i<nums.size();i++){
            int x = nums[i];
            if(x>largest){
                second_l = largest;
                largest=x;
            }
            else if(x>second_l && x<= largest){
                second_l =x;
            }
        }
        return (largest-1) * (second_l-1);
        
    }
};