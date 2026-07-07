class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n=stones.size();
        if(n==1) return stones[0];
        priority_queue<int>pq;
        for(int x:stones){
            pq.push(x);
        }
        while(!pq.empty()){
            if(pq.size()>=2){
                int v1 = pq.top();
                pq.pop();
                int v2= pq.top();
                pq.pop();
                if(v1==v2) continue;
                else (pq.push(v1-v2));
            }
            else if(pq.size ()==1) return pq.top();
            else return 0;
        }
        return 0;
    }
};