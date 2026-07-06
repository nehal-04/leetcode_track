class Solution {
public:
    string removeKdigits(string num, int k) {

        int n=num.size();
        if(num=="0") return "0";
        string ans="";

        stack<int>st;
        st.push(num[0]-'0');
        for(int i=1;i<n;i++){
            while(k>0 && !st.empty() && st.top()  > num[i]-'0' ) {st.pop();k--;}
            st.push(num[i]-'0');
        }

        //for cases like 123456
        while(k>0){
            k--;
            st.pop();
        }

        if(st.empty())return "0";
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }

        //imp if answer seems to be starting with 0 , remove the 0s
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.empty())return "0";
        reverse(ans.begin() , ans.end());
        
        return ans;









        
    }
};