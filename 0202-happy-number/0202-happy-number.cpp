class Solution {
public:
    bool isHappy(int n) {
        int s=0;
        int cur_state=n;
        unordered_set<int>st;
        while(s!=1){
            while(cur_state>0){
                int d=cur_state %10;
                s = s + (d*d);
                cur_state = cur_state / 10;
            }

            if(s==1) return true;
            
            else {
                if(st.find(s) == st.end()){
                    st.insert(s);
                    cur_state = s;
                    s=0;
                    continue;
                }    
                else{
                    return false;
                }
            }
            
        }
        return false;   
    }
};