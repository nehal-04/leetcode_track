class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        //rows and columns same 
        vector<vector<int>>dist(n,vector<int>(n,INT_MIN));
        vector<vector<int>>ways(n,vector<int>(n,0));

        int mod = 1e9 + 7;

        //right , down , downright
        vector<int>dr = {1,0,1};
        vector<int>dc ={0,1,1};
        priority_queue<pair<int,pair<int,int>>> pq;
        
        ways[n-1][n-1]=1;
        dist[n-1][n-1]=0;

        for(int r=n-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(board[r][c] == 'X'){
                    ways[r][c]=0;
                    continue;
                }
                int val;
                if(board[r][c] == 'E'){
                    val=0;
                }
                else{
                    val=board[r][c] -'0';
                }

                for(int i=0;i<3;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<0 || nc<0 || nr>=n || nc>=n || board[nr][nc] == 'X') continue;
                    if(dist[nr][nc] == INT_MIN) continue; // could be when nr nc are x
                    if(val + dist[nr][nc] > dist[r][c]){
                        dist[r][c]=dist[nr][nc] + val;
                        ways[r][c] = ways[nr][nc];
                    }
                    else if(val + dist[nr][nc] == dist[r][c]){
                        ways[r][c] = (ways[r][c] + ways[nr][nc]) % mod;
                    }
                    else{}
                }
            }
        }
        if(dist[0][0] == INT_MIN) return {0,0};
        else return {dist[0][0] , ways[0][0]};
    }
};