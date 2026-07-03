class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<=1) return n;
        int l=0;
        int r=0;
        int maxwindow=INT_MIN;
        vector<int>lastseen(128,-1);
        while(l<=r && r<n){
            char curr=s[r];
            if(lastseen[curr] >= l){
                l = lastseen[curr]+1;     
            }
            lastseen[curr]=r;
            maxwindow=max(maxwindow , r-l+1);
            r++;
        }
        return maxwindow;
    }
};
