class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> s_t;
        unordered_map<char , char>t_s;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(s_t.count(s[i])){
                if(s_t[s[i]] != t[i]) return false;
                else continue;
            }
            else{
                if(t_s.count(t[i])) return false;
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
        }
        return true;

    }
};