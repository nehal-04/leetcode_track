class Solution {
private:
    int gcdhelper(int x , int y){

        while(y!=0){
            int rem = x%y;
            x=y;
            y=rem;
        }
        return x;

    }
    
public:
    int findGCD(vector<int>& nums) {
        int minel=*min_element(nums.begin() , nums.end());
        int maxel=*max_element(nums.begin() , nums.end());
        return gcdhelper(maxel , minel);
    }
};