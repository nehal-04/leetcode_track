class Solution {
private:
    bool helper(string &s){
        int n=s.size();
        string t = s;

        for(int i=0;i<n-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                t[i]='1';
                t[i+1]='0';
            }
        }
        s = t;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0' && s[i+1]=='1') return false;
        }
        return true;
    }
public:
    int secondsToRemoveOccurrences(string s) {
        int steps=0;
        bool check=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0' && s[i+1]=='1') {
                check=true;
                break;
            }
        }
        if(!check) return 0;
        while(true){
            bool ans=helper(s);
            steps++;
            if(ans) return steps;
        }
        return steps;


        
    }
};