class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    void init(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
    }

    int findpar(int x ){
        if(parent[x]==x) return x;
        else return parent[x] = findpar(parent[x]);
    }

    void unionforkruskal(int x , int y){

        int p1=findpar(x);
        int p2 = findpar(y);
        if(p1==p2) return;

        if(rank[p1] > rank[p2]){
            parent[p2]=p1;
        }
        else if (rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            parent[p2]=p1;
            rank[p1]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        init(n);
        int numberofcomponents=0;
        for(vector<int>&v : connections){
            int from = v[0];
            int to = v[1];
            unionforkruskal(from , to);
        }

        for(int i=0;i<n;i++){
            if(parent[i] == i) numberofcomponents++;
        }

        return numberofcomponents-1;
        
    }
};