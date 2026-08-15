class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        
        long long n = nums.size();
        long long ans =0;
        priority_queue<long long>pq;
        for(long long i=0;i<n;i++){
            if(pq.empty() && s[i]=='1') ans += nums[i];
            else if(s[i] =='0') pq.push(nums[i]);
            else if(s[i] == '1') {
                pq.push(nums[i]);
                ans += pq.top();
                pq.pop();
            }
        }
        return ans;

    }
};