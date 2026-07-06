class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq; //store only idx
        for(int i=0;i<k;i++){
            int val=nums[i];
            while(!dq.empty() && nums[dq.back()] < val) dq.pop_back();
            dq.push_back(i);
            
        }
        ans.push_back(nums[dq.front()]);
        //storing only indexes
        for(int i=k;i<n;i++){
            int val=nums[i];
            //every iteration 2 steps , deque jmain structrue , remove elemnt if nto part of sliding window
            while(!dq.empty() && dq.front() < i-k+1) dq.pop_front();
            // if a new element bigger han tha existing elements , existing elements in furturwe can never be max so remove
            while(!dq.empty() && nums[dq.back()] < val)dq.pop_back();

            dq.push_back(i);

            //doubtful wat will amax be?
            ans.push_back(nums[dq.front()]);

        }
        return ans;






        

    }
};