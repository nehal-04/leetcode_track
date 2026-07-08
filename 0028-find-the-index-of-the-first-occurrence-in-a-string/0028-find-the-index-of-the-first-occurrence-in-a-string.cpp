class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1=needle.size();
        int s2=haystack.size();
        if(s1>s2) return -1;
        for(int i=0;i<=s2-s1;i++){
            if(haystack.substr(i,s1) == needle){
                return i;
            }
        }
        return -1;
        
    }
};