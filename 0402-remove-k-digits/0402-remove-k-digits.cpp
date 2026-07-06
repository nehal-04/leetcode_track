class Solution {
public:
    string removeKdigits(string num, int k) {

        int n=num.size();
        if(n==k) return "0";

        string ans="";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && k>0 && st.top() -'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // ip if say 123456 , noral logic wont remove , so remove last ke digit

        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }


        //imp
        while(ans.size() > 0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin() , ans.end());

        if(ans.size()==0 ) return "0";
        return ans;


        
    }
};