class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_el=nums[0];
        int min_idx = 0;
        int max_el = nums[0];
        int max_idx = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < min_el){
                min_el = nums[i];
                min_idx=i;
            }
            else if (nums[i] > max_el){
                max_el = nums[i];
                max_idx = i;
            }
            else{}
        }

        int between_dist = abs(max_idx-min_idx);
        int front = min(min_idx + 1 , max_idx +1) + between_dist;
        int back = min(n- max_idx , n- min_idx) + between_dist; 
        int nousebetween = min({max_idx+1 + n-min_idx , min_idx+1 + n-max_idx} );
        return min({front , back , nousebetween });
        
    }
};