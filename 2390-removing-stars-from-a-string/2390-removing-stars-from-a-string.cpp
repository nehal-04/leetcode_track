class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans ="";
        for(char ch:s){
            if(ch=='*'){
                if(ans.size()>0) ans.pop_back();
            }
            else ans+=ch;
        }
        return ans;
    }

};