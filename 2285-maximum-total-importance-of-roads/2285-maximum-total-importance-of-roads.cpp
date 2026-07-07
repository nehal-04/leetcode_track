class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>city(n);
        vector<int>degree(n,0);
        for(auto& p : roads){
            degree[p[0]]++;
            degree[p[1]]++;
        }
        vector<pair<int,int>> helper;
        for(int i=0;i<n;i++){
            helper.push_back({degree[i] , i});
        }
        sort(helper.begin() , helper.end()); // sorts accd to degree ascending 

        int rank=1;
        for(int i=0;i<n;i++){
            int idx=helper[i].second;
            city[idx]=rank;
            rank++;
        }


        long long ans=0;
        for(vector<int>&v : roads){
            ans = ans + city[v[0]];
            ans = ans + city[v[1]];
        }
        return ans;

    }
};