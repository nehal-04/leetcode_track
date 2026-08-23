class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=1e9 +7;
        vector<vector<pair<int,int>>>adj(n);
        //given atmost 1 road , so givn roads are bidirectional

        for(vector<int>&v:roads){
            int u = v[0];
            int w = v[1];
            int t = v[2];
            adj[u].push_back({w, t});
            adj[w].push_back({u,t});
        }

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        vector<int>ways(n , 0);
        vector<long long>dist(n,LLONG_MAX);
        
        dist[0] = 0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto[cur_d , cur_city] = pq.top();
            pq.pop();

            if(cur_d > dist[cur_city]) continue;
            for(pair<int,int>&v : adj[cur_city]){
                int edge_wt = v.second;
                int neigh = v.first;
                if(cur_d + edge_wt > dist[neigh]) continue;
                else if(cur_d + edge_wt == dist[neigh]){
                    ways[neigh] = (ways[neigh] + ways[cur_city]) % mod;
                }
                else {
                    ways[neigh] = ways[cur_city];
                    dist[neigh] = cur_d + edge_wt;
                    pq.push({dist[neigh] , neigh});
                }
            }

        }
        return ways[n-1];







    }
};