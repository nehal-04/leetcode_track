class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>outdegree(n,0);
        vector<vector<int>>parent_ofidxnode(n);
        queue<int>q;
        
        vector<bool>safe(n,false) ; //to prevent time complexity of sorting by increase space complexity

        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                outdegree[i]=0;
                q.push(i);
                continue;
            }
            for(int y:graph[i]){
                parent_ofidxnode[y].push_back(i);
                outdegree[i]++;
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=true;
            for(int w : parent_ofidxnode[node]){
                outdegree[w]--;
                if(outdegree[w] == 0) q.push(w);
            
            }
        }

        for(int i=0;i<n;i++){
            if(safe[i]==true) ans.push_back(i);
        }
        return ans;

    }
};