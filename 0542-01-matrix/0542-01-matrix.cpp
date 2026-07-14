class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols= mat[0].size();
        vector<vector<int>>nearestzero(rows , vector<int>(cols , -1));
        queue<pair<int,int>>q; // {distfrom0,{row,col}}
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    nearestzero[i][j] =0;
                } 
            }
        }

        vector<int>dr = {-1,1,0,0};
        vector<int>dc={0,0,-1,1};

        //initial pass done , all 0s in queue now we iterate from 0s to find length till 1s
        int dist=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int r=q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr<0 || nc<0 || nr>=rows || nc>=cols || nearestzero[nr][nc]!=-1)continue;
                    nearestzero[nr][nc]=dist;
                    q.push({nr,nc});
                }
            }
            dist++;
        }

        return nearestzero;



    }
};