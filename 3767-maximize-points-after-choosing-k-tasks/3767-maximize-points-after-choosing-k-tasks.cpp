class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long ans=0;
        int n = technique1.size();

        priority_queue<pair<int,int> > pq; // max heap of tech1 - tech 2 for each task where tech 1 dominates tech 2
        vector<long long> tech_effort(n);
        for(int i=0;i<n;i++){
            pq.push({technique1[i] - technique2[i] , i});
        }


        int i=0;
        //first settle k tasks with tech 1 , then in next while loop compare b/w tech1 and tech2 for the rest
        
        while(i<k){
            pair<int,int>p=pq.top();
            pq.pop();
            int idx=p.second;
            int diff=p.first;
            ans += diff + technique2[idx];
            i++;
        }

        while(i<n){
            pair<int,int>p=pq.top();
            pq.pop();
            int idx=p.second;
            int diff=p.first;
            if(diff>0) ans += technique1[idx];
            else ans+= technique2[idx];
            i++;
        }
        return ans;


        
    }
};