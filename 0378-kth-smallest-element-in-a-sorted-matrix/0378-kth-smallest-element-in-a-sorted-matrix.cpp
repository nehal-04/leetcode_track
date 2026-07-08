class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //initial stage setup
        
        int rows=matrix.size();
        int cols = matrix[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq; // {VAL , {I,J}}
        for(int i=0;i<rows;i++){
            pq.push({matrix[i][0] , {i,0}});
        }
        int ctr=0;
        while(!pq.empty() && ctr <= k){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int currow=p.second.first;
            int curcol=p.second.second;
            int val=p.first;
            ctr++;
            if(ctr==k) return val;
            if(curcol + 1 <= matrix[currow].size()-1) {
                pq.push({matrix[currow][curcol+1] , {currow , curcol + 1}});
            }
        }
        return -1;



        
    }
};