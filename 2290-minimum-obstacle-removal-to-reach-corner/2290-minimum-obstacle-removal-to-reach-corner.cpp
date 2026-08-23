class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int , pair<int,int>>>>pq;
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {1 , -1 ,0 ,0};

        while(!pq.empty()){
            int cur_dist = pq.top().first;
            int cur_r = pq.top().second.first;
            int cur_c = pq.top().second.second;
            
            pq.pop();

            if(cur_dist > dist[cur_r][cur_c]) continue;

            for(int i=0;i<4;i++){
                int new_r = cur_r + dr[i];
                int new_c = cur_c + dc[i];
                if(new_r <0 || new_c <0 || new_r == r || new_c == c) continue;
                int edge_wt = (grid[new_r][new_c] == 1) ? 1 : 0;

                if(cur_dist + edge_wt < dist[new_r][new_c]){
                    dist[new_r][new_c] = cur_dist + edge_wt;
                    pq.push({dist[new_r][new_c] , {new_r , new_c}});
                }
            }

        }
        return dist[r-1][c-1];
    }
};