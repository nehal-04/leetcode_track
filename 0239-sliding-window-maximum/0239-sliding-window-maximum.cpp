class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        //first make for k elements then later 
        for(int i=0;i<k;i++){
            if(dq.empty()) dq.push_back(i);
            else{
                while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
                dq.push_back(i);
            }
        }

        ans.push_back(nums[dq.front()]);

        // now each element entry after the first k elements

        for(int i=k;i<n;i++){
            // 2 things , first if new element greater , keep popping , then secondly while the first element is out of rangee keep popping then add into answer

            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        

    }
};