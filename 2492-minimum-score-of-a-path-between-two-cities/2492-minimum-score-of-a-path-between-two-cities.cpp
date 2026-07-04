class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>visited(n+1,false);
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&p : roads){
            adj[p[0]].push_back({p[1] , p[2]});
            adj[p[1]].push_back({p[0] , p[2]});
        }

        queue<int>q;
        q.push(1);
        int min_incomponent=INT_MAX;

        while(!q.empty()){
            int city=q.front();
            q.pop();
            visited[city] =true;
            for(auto&p : adj[city]){
                if(!visited[p.first]){
                    min_incomponent = min(p.second , min_incomponent);
                    q.push(p.first);
                }
            }
        }
        return min_incomponent;


            
    }
};