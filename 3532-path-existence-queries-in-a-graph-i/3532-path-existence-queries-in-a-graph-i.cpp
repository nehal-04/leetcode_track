class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int i=n-1;
        vector<int>visited(n,-1);
        int component=0;
        visited[n-1]=0;
        while(i>=1){
            if(nums[i]  - nums[i-1] <= maxDiff){
                visited[i-1]=component;
            }
            else{
                component++;
                visited[i-1]=component;
            }
            i--;
        }
        
        int sz=queries.size();
        vector<bool>ans(sz);
        for(int i=0;i<sz;i++){
            int from = queries[i][0];
            int to = queries[i][1];
            if(visited[from] == visited[to]) ans[i]=true;
            else ans[i]=false;
        }
        return ans;


        
    }
};