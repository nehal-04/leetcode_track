class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-k-1;
        int cur_windowsum=0;
        int tot_windowsum =0;
        for(int i=0;i<n;i++){
            tot_windowsum += cardPoints[i];
            if(i< n-k) cur_windowsum += cardPoints[i];
        }
        if(k==n) return tot_windowsum;
        int ans=0;
        while(r<n){
            ans=max(ans , tot_windowsum - cur_windowsum);
            cur_windowsum -= cardPoints[l];
            l++;
            r++;
            if(r==n) break;
            cur_windowsum += cardPoints[r]; 
        }
        return ans;
    }
};