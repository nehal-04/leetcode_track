class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans="";
        int s=0;
        while(n>0){
            int d=n%10;
            if(d==0){n=n/10;continue;}
            s += d;
            ans+= to_string(d);
            n=n/10;
        }   
        long long no=0;
        for(int i=ans.size()-1;i>=0;i--){
            no = no*10 + (ans[i]-'0');
        }
        no *= s;
        return no;
        
    }
};