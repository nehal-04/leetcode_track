class Solution {
private:
    int finddigitrange(int num){
        int min_digit = INT_MAX;
        int max_digit = INT_MIN;
        if(num==0) return 0;
        while(num>0){
            int d=num%10;
            min_digit = min(min_digit , d);
            max_digit = max(max_digit , d);
            num=num /10;
        }
        return max_digit - min_digit;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int sum=0;
        int max_range=0;
        for(int i=0;i<nums.size();i++){
            int dig_r = finddigitrange(nums[i]);
            if(dig_r > max_range){
                max_range=dig_r;
                sum=nums[i];
            }
            else if(dig_r == max_range){
                sum += nums[i];
            }
            else{}
        }
        return sum;
        
    }
};