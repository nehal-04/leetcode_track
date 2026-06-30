class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        
        vector<vector<int>> effort(rows , vector<int>(cols , INT_MAX));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        effort[0][0]=0;
        //up , down , left, right
        vector<int> dr= {0,0,-1,1};
        vector<int> dc= {1,-1,0,0};

        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int cur_effort=p.first;
            int r =p.second.first;
            int c=p.second.second;

            if(cur_effort > effort[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r + dr[i];
                int nc=c + dc[i];
                if(nr<0 || nr>=rows || nc<0 || nc>=cols) continue;
                int neweffort= max(abs(heights[nr][nc] - heights[r][c]) , cur_effort);
                if(neweffort < effort[nr][nc]){
                    effort[nr][nc] = neweffort;
                    pq.push({neweffort , {nr,nc}});
                }

            }

        }
        return effort[rows-1][cols-1];

    }
};