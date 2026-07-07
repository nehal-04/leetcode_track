class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>lastseen(3,-1);
        int r=0;
        int ans=0;
        while(r< n){
            lastseen[s[r]-'a'] = r;
            int lowest_idx = *min_element(lastseen.begin(),lastseen.end());
            if(lowest_idx==-1) {r++;continue;}
            ans += lowest_idx + 1;
            r++;
            
        }
        return ans;
        
    }
};