class Solution {
public:
    string smallestSubsequence(string s) {

        int n=s.size();
        unordered_map<char,int>mp;
        stack<char>st;
        for(char c:s) mp[c]++;
        vector<bool>inans(26,0);
        for(char c:s){
            if(inans[c-'a']) {
                mp[c]--;
                continue;
            }

            while(!st.empty() && st.top() > c && mp[st.top()]>0){
                inans[st.top()-'a']=false;
                st.pop();
            }

            st.push(c);
            mp[c]--;
            inans[c-'a']=true;
        }

        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};