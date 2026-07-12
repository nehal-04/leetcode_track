class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i] , i});
        }

        int rank=0;
        int prevval = INT_MIN;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int val=p.first;
            int idx=p.second;
            ans[idx]=rank;
            if(val==prevval) ans[idx]=rank;
            else{
                rank++;
                ans[idx]=rank;
            }
            prevval=val;
        }
        return ans;
        
    }
};