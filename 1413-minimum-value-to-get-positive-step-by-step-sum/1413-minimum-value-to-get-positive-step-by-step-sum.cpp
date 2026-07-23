class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int cursum =1;
        //curusm never less than 1 
        int fin_ans =1 ;
        for(int i=0;i<n;i++){
            cursum += nums[i];
            if(cursum < 1){
                fin_ans += 1-cursum ;
                cursum=1;
            }
        }
        return fin_ans;
        
    }
};