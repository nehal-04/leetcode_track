class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        char curchar=ans[0];
        int curc=1;
        int i=1;
        n--;
        while(n>0){
            string preiter="";
            while(i<ans.size()){
                if(ans[i] == curchar) curc++;
                else{
                    preiter += to_string(curc);
                    preiter += curchar;
                    curchar = ans[i];
                    curc=1; 
                }
                i++;
            }

            preiter += to_string(curc);
            preiter += curchar;
            ans = preiter;
            curchar=ans[0];
            curc=1;
            i=1;   
            n--;
        }
        return ans;



    }
};