class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<=1) return n;
        unordered_set<char> existing;
        int l=0;
        int r=0;
        int maxwindow=0;
        while(l<=r && r<n){
            auto it= existing.find(s[r]);
            if(it == existing.end()){
                existing.insert(s[r]);
                maxwindow=max(r-l+1,maxwindow);
            }
            else{
                while(l<=r && existing.find(s[r]) != existing.end()){
                    existing.erase(s[l]);
                    l++;
                }
                existing.insert(s[r]);
            }
            r++;
        }
        return maxwindow;
    }
};