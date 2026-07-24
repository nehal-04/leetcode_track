class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {

        int initial_sum =0;
        int n = reward2.size();
        for(int i=0;i<n;i++){
            initial_sum += reward2[i];
        }
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(reward1[i] - reward2[i]);
        }
        int ctr=0;
        while(!pq.empty() && ctr<k){
            int val = pq.top();
            pq.pop();
            initial_sum += val;
            ctr++;
        }
        return initial_sum;
        
    }
};