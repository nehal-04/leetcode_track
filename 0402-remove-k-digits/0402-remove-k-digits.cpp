class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num=="0" || num =="1") return "0";
        
        int n = num.size();
        string ans ="";
        stack<int>st;
        st.push(num[0] -'0');
        for(int i=1;i<n;i++){
            while(k>0 && !st.empty() && st.top()> num[i] - '0'){
                st.pop();
                k--;
            }
            st.push(num[i] -'0');
        }

        // for cases like 123456
        while(k>0){
            st.pop();
            k--;
        }

        // now number at top should come at end first put it at the beginnign and check
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }

        // 00000 if in the end 
        while(ans.size() > 0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size() == 0) return "0";
        reverse(ans.begin() , ans.end());
        return ans;
    }
};