class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        if (grid.size() == 1 && grid[0].size() == 1){
            if(k>grid[0][0]) return 0;
            else return -1;
        }
        
        vector<vector<int>> obstacles_used(grid.size() , vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        q.push({0,0});
        obstacles_used[0][0]=grid[0][0];
        //up down left right
        vector<int>dr={0,0,-1,1};
        vector<int>dc={1,-1,0,0};
        
        int l=0;

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int>p=q.front();
                q.pop();
                int cur_x=p.first;
                int cur_y=p.second;
                int cur_obst = obstacles_used[cur_x][cur_y];
                for(int i=0;i<4;i++){
                    int nr=cur_x + dr[i];
                    int nc=cur_y + dc[i];
                    if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size()) continue;
                    int new_obst = (grid[nr][nc] == 1)?cur_obst +1:cur_obst;
                    if(new_obst>k) continue;
                    else if (nr == grid.size()-1 && nc == grid[0].size()-1) return l+1;
                    else if (obstacles_used[nr][nc] > new_obst){
                        obstacles_used[nr][nc]=new_obst;
                        q.push({nr,nc});
                    }
                }
            }
            l++;
        }

        if(obstacles_used[grid.size()-1][grid[0].size()-1] == INT_MAX) return -1;
        else return l;


    }
};