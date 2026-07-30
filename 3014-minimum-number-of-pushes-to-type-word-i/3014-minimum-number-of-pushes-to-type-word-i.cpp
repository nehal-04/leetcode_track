class Solution {
public:
    int minimumPushes(string word) {
        vector<int>helper(26,0);
        for(char c:word){
            helper[c-'a']++;
        }
        sort(helper.begin(),helper.end() , greater<int>());
        int ctr=0;
        int ans =0;
        int cur_multiplier=1;
        for(int i=0;i<26;i++){
            if(helper[i] == 0) break;
            if(ctr<8){
                ans += cur_multiplier*helper[i];
                ctr++;
            }
            else{
                cur_multiplier++;
                ans += cur_multiplier*helper[i];
                ctr=1;
            }
        }
        return ans;
    }
};