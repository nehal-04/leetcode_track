class Solution {
private:
    vector<int> nse_foreach(vector<int>&arr){
        int n=arr.size();
        vector<int>nse_idxforeach(n);
        stack<pair<int,int>>st;
        nse_idxforeach[n-1]=n;
        st.push({arr[n-1], n-1});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().first >= arr[i]) st.pop();
            if(st.empty()){
                nse_idxforeach[i]=n;
                st.push({arr[i],i});
            }
            else{
                nse_idxforeach[i] = st.top().second;
                st.push({arr[i],i});
            }
        }
        return nse_idxforeach;
    }

    vector<int> pse_foreach(vector<int>&arr){
        int n=arr.size();
        vector<int>pse_idxforeach(n);
        stack<pair<int,int>>st;
        pse_idxforeach[0]=-1;
        st.push({arr[0],0});
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top().first>arr[i])st.pop();
            if(st.empty()){
                pse_idxforeach[i]=-1;
                st.push({arr[i],i});
            }
            else{
                pse_idxforeach[i]=st.top().second;
                st.push({arr[i],i});
            }
        }
        return pse_idxforeach;
    }


public:

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int mod =1e9 +7;
        vector<int>pse_idxforeach = pse_foreach(arr);
        vector<int>nse_idxforeach = nse_foreach(arr);
        for(int i=0;i<n;i++){
            int toleftmin= i-pse_idxforeach[i] ;
            int torightmin = nse_idxforeach[i] - i;
            int sum_here= (1LL*toleftmin*torightmin*arr[i])%mod;
            ans = (ans+sum_here)%mod; 
        }
        return ans;

    }
};