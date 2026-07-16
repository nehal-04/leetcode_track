class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l=1;
        int h = *max_element(piles.begin(), piles.end());
        int ans = h;
        while(l<=h){
            int curspeed= l + (h-l)/2;
            long long used_hrs =0;
            for(int i=0;i<piles.size();i++){
                if( piles[i] % curspeed ==0) used_hrs += piles[i]/curspeed;
                else used_hrs += piles[i]/curspeed + 1;

                if(used_hrs >hrs) break;
            }

            if(used_hrs <= hrs){
                ans=curspeed;
                h=curspeed-1;
            }
            else l = curspeed + 1;
        } 
        return ans;

    }
};