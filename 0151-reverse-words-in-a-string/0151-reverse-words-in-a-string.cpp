class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=n-1;
        while(i>=0){

            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            int e=i;
            while(i>=0 && s[i] != ' ')i--;
            int start = i+1;
            ans+= s.substr(start , e - start + 1);
            if(i+1!=0) ans += ' ';
            
        }
        int e = ans.size()-1;
        while(e>=0 && ans[e]==' ')e--;
        ans=ans.substr(0,e+1);
            
        return ans;
    }
};