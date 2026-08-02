class Solution {
private:
    int reqdbitofnumber(int place_from_right , int number){
        return number >> place_from_right & 1;
    }
public:
    int singleNumber(vector<int>& nums) {

        // for all digits
        int final_ans =0;

        for(int i=0;i<32;i++){
            int here_sum = 0;
            for(int num : nums){
                here_sum += reqdbitofnumber(i,num);
            } 
            int final_bit_here = here_sum % 3;
            final_ans = final_ans |  final_bit_here << i ;
        }

        return final_ans;
    }
};