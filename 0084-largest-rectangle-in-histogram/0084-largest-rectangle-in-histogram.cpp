class Solution {
private:
    vector<int>findnse(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,n);

        stack<int>st;// contains indices 
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i]= st.top();
            st.push(i);
        }
        return ans;

    }

    vector<int>findpse(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,-1);

        stack<int>st;// contains indices 
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i]= st.top();
            st.push(i);
        }
        return ans;

    }
public:
    int largestRectangleArea(vector<int>& heights) {

        int max_ans =0;
        int n = heights.size();
        vector<int> nse_foreach = findnse(heights);
        vector<int>pse_foreach = findpse(heights);
        for(int i=0;i<n;i++){
            int to_left = i-pse_foreach[i];
            int to_right = nse_foreach[i] - i;
            int val = (to_left + to_right - 1) * heights[i];
            max_ans = max(max_ans , val);
        }
        return max_ans;
        
       

    }
};