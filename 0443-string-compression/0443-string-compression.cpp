class Solution {
public:
    int compress(vector<char>& chars) {

        string s="";
        char curchar=chars[0];
        int curc=1;
        int i=1;
        while(i<chars.size()){
            if(chars[i] == curchar) curc++;
            else{
                s += curchar;
                if(curc>1) s += to_string(curc);
                curchar=chars[i];
                curc=1;
            }
            i++;
        }
        s += curchar;
        if(curc>1) s += to_string(curc);

        i=0;
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }

        chars.resize(s.size());

        return chars.size();


        
    }
};