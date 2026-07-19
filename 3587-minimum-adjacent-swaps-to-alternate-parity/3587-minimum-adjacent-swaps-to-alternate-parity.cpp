class Solution {
private:
    int helper(vector<int>&indices , int state){
        int ans =0;
        int curr_target_idx = 0;
        if(state == 1){
            // odd numbers at even indices
            for(int x:indices){
                ans += abs(x - curr_target_idx);
                curr_target_idx +=2;
            }
        }
        else{
            //even numbers at even indices
            for(int x: indices){
                ans += abs(x-curr_target_idx);
                curr_target_idx +=2;
            }
        }

        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<int>evenindices;
        vector<int>oddindices;
        for(int i=0;i<nums.size() ; i++){
            if(nums[i] % 2 ==0) evenindices.push_back(i);
            else oddindices.push_back(i);
        }

        if (evenindices.size() > oddindices.size() + 1 || oddindices.size() > evenindices.size() + 1) return -1;

        int state = 0; // state = 0 if odd numers = even numbers in size , 1 if odd numbers greater than even and 2 if even numbers greater than odd

        if(oddindices.size() > evenindices.size()) state =1;
        else if(evenindices.size()>oddindices.size()) state =2;
        else{}

        if(state == 1){
            return helper(oddindices , 1);
        }
        else if (state == 2){
            return helper(evenindices , 2);
        }
        else return min (helper(oddindices,1) , helper(evenindices,2));

    }
};