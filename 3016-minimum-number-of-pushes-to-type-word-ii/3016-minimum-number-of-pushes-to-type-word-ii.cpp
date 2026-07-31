class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());

        int cur_multiplier=1;
        int ans=0;
        int ctr=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i] == 0) return ans;
            if(ctr<8){
                ans += cur_multiplier * freq[i];
                ctr++;
            }
            else{
                ctr=1;
                cur_multiplier++;
                ans += cur_multiplier * freq[i];
            }
        }
        return ans;
    }
};