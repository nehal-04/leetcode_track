class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());


        int l=0;
        int r=1;
        int long_strk_hor=1;
        while(l<r && r<hBars.size()){
            if(hBars[r] == hBars[r-1]+1){
                
                long_strk_hor=max(r-l+1 , long_strk_hor);
                r++;
            }
            else{
                l=r;
                r++;
            }
        }

        int best_hor= long_strk_hor+1;

        l=0;
        r=1;
        int long_strk_ver=1;
        while(l<r && r<vBars.size()){
            if(vBars[r] == vBars[r-1]+1){
                long_strk_ver = max(r-l+1 , long_strk_ver);
                r++;
            }
            else{
                l=r;
                r++;
            }
        }

        int best_ver=long_strk_ver+1;
        int side=min(best_hor , best_ver);
        return side*side;



        
    }
};