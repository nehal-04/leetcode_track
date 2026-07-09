class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int>freq(n,0);
        vector<unordered_set<int>> adj(n);

        for(vector<int>&v : roads){
            int from = v[0];
            int to= v[1];
            freq[from]++;
            freq[to]++;
        
            adj[from].insert(to);
            adj[to].insert(from);
        }

        int maxans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ct=0;
                if(adj[i].find(j) != adj[i].end()) ct=-1;
                ct += freq[i] + freq[j];
                maxans = max(maxans , ct); 
            }
        }
        return maxans;

        


    }
};