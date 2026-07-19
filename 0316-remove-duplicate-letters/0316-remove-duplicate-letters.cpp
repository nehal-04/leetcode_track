class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<bool>inAns(26,0);
        stack<char>st;
        for(char c : s){
            if(inAns[c-'a']){
                mp[c]--;
                continue;
            }
            while(!st.empty() && st.top() > c && mp[st.top()] > 0){
                inAns[st.top()-'a']=false;
                st.pop();
                
            }
            st.push(c);
            inAns[c-'a']=true;
            mp[c]--;
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;


        
        
    }
};