class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        

        // the floyd warshall algorithm
        vector<vector<long long>>adj(n , vector<long long>(n,INT_MAX));
        for(vector<int>&v : edges){
            long long from = v[0];
            long long to= v[1];
            long long  wt = v[2];
            adj[from][to] = wt;
            adj[to][from]=wt;
        }

        for(int i=0;i<n;i++) adj[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        int ans=0;
        int mincities=INT_MAX;
        int curcount =0;
        for(int i=0;i<n;i++){
            curcount=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(adj[i][j] <= distanceThreshold){
                    curcount++;
                    if(curcount>mincities) break;
                }
            }
            if(curcount <= mincities){
                mincities=curcount;
                ans = i;
            }
        }
        return ans;

    }
};