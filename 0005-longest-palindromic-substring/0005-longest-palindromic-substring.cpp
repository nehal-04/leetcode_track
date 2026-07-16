class Solution {
public:
    string longestPalindrome(string s) {

       int n=s.size();
       int curlen=0;
       int maxlen =0;
       int start=0;
       int i=0;
       while(i<n){

        //first for odd lengthed string centred around s[i]
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l] == s[r]){
            curlen = r-l+1;
            maxlen = max(maxlen , curlen);
            if(curlen == maxlen) start=l;
            l--;
            r++;
        }

        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l] == s[r]){
            curlen = r-l+1;
            maxlen=max(maxlen,curlen);
            if(maxlen==curlen) start=l;
            l--;
            r++;
        }

        i++;
       }
       return s.substr(start,maxlen);
        
    }
};