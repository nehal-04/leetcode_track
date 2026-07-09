class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        int mod=1e9+7;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin() , vFences.end());

        vector<int>updated_hfences;
        updated_hfences.push_back(1);
        for(int x:hFences){
            updated_hfences.push_back(x);
        }
        updated_hfences.push_back(m);


        vector<int>updated_vfences;
        updated_vfences.push_back(1);
        for(int x:vFences){
            updated_vfences.push_back(x);
        }
        updated_vfences.push_back(n);

        int sz1=updated_hfences.size();
        unordered_set<int>sizes_hor; 
        for(int i=0;i<sz1;i++){
            for(int j=i+1;j<sz1;j++){
                int diff = updated_hfences[j] - updated_hfences[i];
                sizes_hor.insert(diff);
            }
        }

        int sz2=updated_vfences.size();
        int maxsize=0;
        for(int i=0;i<sz2;i++){
            for(int j=i+1;j<sz2;j++){
                int d=updated_vfences[j] - updated_vfences[i];
                if(sizes_hor.find(d) != sizes_hor.end()){
                    maxsize = max(maxsize , d);
                }
            }
        }
        

        if(maxsize==0) return -1;

        return (1LL*maxsize*maxsize) % mod;





        

    }

};