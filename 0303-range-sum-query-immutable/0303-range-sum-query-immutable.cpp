class NumArray {
private:
    vector<int>prefix_sum;
    void initial_setup(vector<int>&nums){
        int cursum =0;
        for(int i =0;i<nums.size();i++){
            cursum += nums[i];
            prefix_sum[i] = cursum;
        }
    }
public:

    NumArray(vector<int>& nums) {
        int n =nums.size();
        prefix_sum.resize(n);
        initial_setup(nums);
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix_sum[right];
        return prefix_sum[right] - prefix_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */