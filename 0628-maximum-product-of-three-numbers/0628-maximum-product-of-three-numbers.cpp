class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //keep track of 3 numbers max , second max , third max , min ,second min 
        //if more thequal to tow negtive numbers then minimun*secondmin*max will be answer 
        //in other cases max*secondmax*thirdmax i sanswer
        int max_no = -1001;
        int second_max_no = max_no;
        int third_max_no = second_max_no;
        int min_no = 1001;
        int second_min_no = min_no;

        for (int i=0;i<nums.size();i++){
            //handle max case
            int num = nums[i];
            if(num >= max_no) {
                third_max_no = second_max_no;
                second_max_no=max_no;
                max_no = num;
            }
            else if(num < max_no && num >= second_max_no){
                third_max_no = second_max_no;
                second_max_no = num;
            }
            else if(num < second_max_no && num >= third_max_no) third_max_no = num;


            // now min handling
            if(num <= min_no){
                second_min_no = min_no;
                min_no = num;
            }
            else if(num > min_no && num <= second_min_no) second_min_no = num;
        }

        return max( max_no * second_max_no * third_max_no, max_no * min_no * second_min_no );
    }
};