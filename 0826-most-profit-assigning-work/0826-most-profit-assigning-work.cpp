class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        sort(worker.begin() , worker.end());
        int ans=0;
        vector<pair<int,int>> diff_prof;
        for(int i=0;i<difficulty.size();i++){
            int diff=difficulty[i];
            int prof=profit[i];
            diff_prof.push_back({diff,prof});
        }
        sort(diff_prof.begin() , diff_prof.end());
        
        int cur_max_prof=0;
        int cur_idx=0;
        int i=0;
        while(i<worker.size()){
            int cur_worker=worker[i];
            while(cur_idx < diff_prof.size() && diff_prof[cur_idx].first <= cur_worker){
                cur_max_prof = max(cur_max_prof , diff_prof[cur_idx].second);
                cur_idx++;
            }
            cur_idx;
            ans+=cur_max_prof;
            i++;
        }

        return ans;
    }
};