class Solution {
private:
    vector<int>parent_alice;
    vector<int>parent_bob;
    vector<int>rank_alice;
    vector<int>rank_bob;
    void init(int n){
        parent_alice.resize(n+1);
        rank_alice.resize(n+1);
        parent_bob.resize(n+1);
        rank_bob.resize(n+1);
        for(int i=1;i<=n;i++){
            parent_alice[i]=i;
            parent_bob[i]=i;
            rank_alice[i] =0;
            rank_bob[i]=0;
        }
    }

    int findpar(int x , bool reqd){
        //reqd =false alice
        //reqd =true bob
        if(!reqd){
            if(parent_alice[x] == x) return x;
            else return parent_alice[x] = findpar(parent_alice[x] , false);
        }

        else{
            if(parent_bob[x] ==x) return x;
            else return parent_bob[x] = findpar(parent_bob[x] , true);
        }

    }

    bool union_helper(int x , int y , bool reqd){
        int p1 = findpar(x,reqd);
        int p2= findpar(y,reqd);
        if(p1==p2) return false;
        if(!reqd){
            //handling alice case
            if(rank_alice[p1] < rank_alice[p2]){
                parent_alice[p1]=p2;
            }
            else if(rank_alice[p2] < rank_alice[p1]){
                parent_alice[p2]=p1;
            }
            else{
                parent_alice[p1]=p2;
                rank_alice[p2]++;
            }
        }

        if(reqd){
            //handling bob case
            if(rank_bob[p1] < rank_bob[p2]){
                parent_bob[p1]=p2;
            }
            else if(rank_bob[p2] < rank_bob[p1]){
                parent_bob[p2]=p1;
            }
            else{
                parent_bob[p1]=p2;
                rank_bob[p2]++;
            }
        }
        return true;
    }

    int numberofcomponents(bool reqd){
        int ans=0;
        if(!reqd){
            //alice case
            for(int i=1;i<parent_alice.size();i++){
                if(parent_alice[i] == i) ans++;
            }
        }
        else{
            for(int i=1;i<parent_bob.size();i++){
                if(parent_bob[i] == i) ans++;
            }
        }
        return ans;

    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        //as in both it is greediuly beneficial to insert type 3 edges before hand as they can be travbersed by both alice and bob , later i tw nodes have type 1 or 2 or btohg and type 3 come there it is always bertter that onyl typ3 stay , greedy approach

        sort(edges.begin() , edges.end() , [](const vector<int>&a , const vector<int>&b){
            return a[0] > b[0];
        });

        init(n);

        int edge_insert_ct=0;
        for(vector<int>&v : edges){
            int type = v[0];
            int from = v[1];
            int to=v[2];
            bool x=false , y=false;
            if(type==3){
                //first for alice 
                x = union_helper(from , to , false);
                
                y = union_helper(from , to ,true);
                
                if(x||y) edge_insert_ct++;
            }
            else if(type ==2){
                if(union_helper(from , to , true)) edge_insert_ct++;
            }
            else{
                if(union_helper(from , to , false)) edge_insert_ct++;
            }
        }


        // now see to it tht both graphs have number of components=1;
        int ct1 = numberofcomponents(false);
        int ct2 = numberofcomponents(true);
        if(ct1==1 && ct2 == 1)return edges.size() - edge_insert_ct;
        else return -1;

        


        
    }
};