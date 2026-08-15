class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int>indegree(n,0);
        for(vector<int>&v : edges){
            int from = v[0];
            int to = v[1];
            indegree[to]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) ans.push_back(i);
        }

        if(ans.size() != 1) return -1;
        return ans[0];
    }
};