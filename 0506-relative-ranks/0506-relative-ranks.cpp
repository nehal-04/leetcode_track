class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>> pq; // {score,idx}
        for(int i=0 ; i<n;i++){
            pq.push({score[i] , i});
        }
        vector<string>ans(n);
        int i=1;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int idx = p.second;
            if(i==1){
                ans[idx] = "Gold Medal";
            }
            else if (i==2){
                ans[idx] = "Silver Medal";
            }
            else if(i==3){
                ans[idx] = "Bronze Medal";
            }
            else{
                ans[idx] = to_string(i);
            }
            i++;
        }
        return ans;

    }
};