class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int,vector<int> , greater<int>> pq;
        for(int x:nums){
            pq.push(x);
        }
        for(int i=0;i<n;i++){
            int val=pq.top();
            pq.pop();
            nums[i]=val;
        }
        return nums;
        
    }
};