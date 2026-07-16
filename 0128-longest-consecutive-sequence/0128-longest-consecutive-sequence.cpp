class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>st;
        int n=nums.size();
        if(n<=1) return n;
        for(int i = 0;i<n;i++) st.insert(nums[i]);

        int curlen =1;
        int maxlen=1;
        for(int x:st){
            int num = x;
            if(st.find(num - 1) == st.end()){
                //start o a sequene
                while(st.find(num+1) != st.end()){
                    num=num+1;
                    curlen ++;
                    maxlen = max(maxlen , curlen);
                }
                curlen=1;
            }
        }
        return maxlen;

        
    }
};