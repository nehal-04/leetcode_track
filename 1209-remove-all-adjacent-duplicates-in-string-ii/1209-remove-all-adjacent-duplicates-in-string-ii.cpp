class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.size();
        string ans="";
        stack<pair<char,int>>st;
        
        st.push({s[0] , 1});
        int i=1;

        while(i<n){
            if(!st.empty() && s[i]==st.top().first){
                int ct=st.top().second + 1;
                if(ct==k){
                    for(int j=0;j<k-1;j++) st.pop();
                    i++;
                    continue;
                }
                else st.push({s[i],ct});
            }
            else{
                st.push({s[i],1});
            }
            i++;
        }

        while(!st.empty()) {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};