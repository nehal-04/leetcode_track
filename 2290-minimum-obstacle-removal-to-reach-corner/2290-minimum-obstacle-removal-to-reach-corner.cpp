class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        deque<pair<int , int>> dq;

        dq.push_back({0,0});
        dist[0][0] = 0;

        vector<int>dr = {0,0,1,-1};
        vector<int>dc = {1 , -1 , 0 , 0};

        while(!dq.empty()){
            auto[cur_r , cur_c]= dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int new_r = cur_r + dr[i];
                int new_c = cur_c + dc[i];
                if(new_r <0 || new_c < 0 || new_r >= r || new_c >=c)continue;

                int edge_wt = grid[new_r][new_c];
                if(dist[cur_r][cur_c] + edge_wt < dist[new_r][new_c]){
                    dist[new_r][new_c] = dist[cur_r][cur_c] + edge_wt;
                    if(edge_wt ==0) dq.push_front({new_r , new_c});
                    else dq.push_back({new_r , new_c});
                }

            }
        }
        return dist[r-1][c-1];

    }
};