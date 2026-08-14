class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen =0;
        int l = 0;
        int r = 0;
        while(l<=r && r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen , r-l+1);
            r++;
        }
        return maxlen;

    }
};