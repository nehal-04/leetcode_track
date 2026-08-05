class Solution {
private:
    void dfs(vector<vector<int>>&adj , int curr , vector<bool>&suspicious){
        if(suspicious[curr]) return;

        suspicious[curr]=true;
        for(int neigh:adj[curr]){
            if(!suspicious[neigh]) dfs(adj , neigh,suspicious );
        }
        
    }    
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(vector<int>&v : invocations){
            adj[v[0]].push_back(v[1]);
        }
        vector<bool>suspicious(n,false);
        dfs(adj,k,suspicious);

        unordered_set<int>sus;

        bool check=false;
        for(vector<int>&v:invocations){
            int first=v[0];
            int sec = v[1];
            if(!suspicious[first]  && suspicious[sec]){
                check = true;
                break;
            }
        }
        vector<int>fin_arr;
        for(int i=0;i<n;i++) fin_arr.push_back(i);

        if(check) return fin_arr;
        fin_arr.clear();
        for(int i=0;i<n;i++){
            if(!suspicious[i]) fin_arr.push_back(i); 
        } 
        return fin_arr;


        
    }
};