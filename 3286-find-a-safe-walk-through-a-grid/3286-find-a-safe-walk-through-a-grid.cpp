class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        vector<vector<int>> battery_used(grid.size() , vector<int>(grid[0].size() , INT_MAX));
        deque<pair<int,pair<int,int>>> dq;
        dq.push_back({grid[0][0],{0,0}});
        battery_used[0][0]=grid[0][0];
        
        // up down left right
        vector<int>dr={0,0,-1,1};
        vector<int>dc={1,-1,0,0};
        while(!dq.empty()){
            
            pair<int,pair<int,int>>p = dq.front();
            dq.pop_front();
            int cur_health = p.first;
            int cur_r= p.second.first;
            int cur_c = p.second.second;
            if(battery_used[cur_r][cur_c] < cur_health) continue;
            for(int i=0;i<4;i++){
                int nr=cur_r + dr[i];
                int nc= cur_c + dc[i];
                if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size()) continue;
                int neigh_batteryused;
                if(grid[nr][nc]==1) neigh_batteryused = cur_health +1;
                else neigh_batteryused=cur_health;
                if(neigh_batteryused < battery_used[nr][nc]){
                    battery_used[nr][nc] = neigh_batteryused;
                    if(neigh_batteryused == cur_health +1) dq.push_back({neigh_batteryused ,{nr,nc}});
                    else dq.push_front({neigh_batteryused , {nr , nc}});
                }
            }
            
        }
        int fin_batteryused= battery_used[grid.size()-1][grid[0].size()-1];
        if(fin_batteryused <= health-1)return true;
        return false;

    }
};