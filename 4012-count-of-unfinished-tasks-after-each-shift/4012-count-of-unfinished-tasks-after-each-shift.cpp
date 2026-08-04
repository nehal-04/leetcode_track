class Solution {
private:
    int helper_bin_upperbound(vector<long long>&prefix, int start , int end , long long target){
        // as alreadty sorted as prefix sum
        int ans = end ;
        while(start<= end){
            int mid = start + (end-start)/2;
            if(prefix[mid] > target){
                ans = mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }    
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n=tasks.size();

        long long total_task_time = 0;
        
        vector<long long>prefix_help(n,0);
        prefix_help[0] = tasks[0];
        for(int i=0;i<n;i++) {
            int num = tasks[i];
            total_task_time += num;
            if(i>0) prefix_help[i] = prefix_help[i-1] + tasks[i];
        }


        // we can use prefix sum for bianry search help so for each task we do searchc within log n?

        long long cur_work =0;
        int curr=0;
        vector<int>ans;
        while(curr<shifts.size()){
            cur_work += shifts[curr];
            if(cur_work >= total_task_time){
                ans.push_back(0);
                cur_work =0;
            }
            else{
                int idx = helper_bin_upperbound(prefix_help , 0 , n - 1, cur_work) ;
                ans.push_back(n-idx);
            }

            curr++;
        }
        return ans;


        
    }
};