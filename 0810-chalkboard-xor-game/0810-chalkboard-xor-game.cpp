class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xor_init = 0;
        int n = nums.size();
        for(int x:nums) xor_init ^= x;
        if(xor_init == 0 ) return true;
        // base case


        if(n%2==0)return true;
        else return false;

        
    }
};