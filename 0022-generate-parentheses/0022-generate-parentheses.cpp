class Solution {
private:
    void helper(vector<string>&ans , int& open , int& close , string& curstring , int n){
        if(close > open) return;
        if(open==n && close==n){
            ans.push_back(curstring);
        }
        bool check_rec1=false;
        if(open<n){
            curstring += '(';
            check_rec1=true;
            open=open+1;
            helper(ans , open , close,curstring ,n);
        }
        if(check_rec1) {
            curstring.erase(curstring.size()-1 , 1);
            open--;
        }

        bool check_rec2=false;

        if(close<open){
            curstring += ')';
            close=close+1;
            check_rec2=true;
            helper(ans,open,close,curstring,n);
        } 
        if(check_rec2){
            curstring.erase(curstring.size()-1,1);
            close--;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0;
        int close=0;
        string c="";
        helper(ans,open,close,c,n);
        return ans;
        
    }
};