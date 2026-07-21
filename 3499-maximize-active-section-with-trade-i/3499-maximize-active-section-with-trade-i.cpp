class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        //split into 0-1 pair how
        int one_ct=0;
        // if we divide into pairs by addressing a set of same elemtns continuous with smsth like say 1 1 1 0 0 then 1 1 1 can be addressed as 3 but 00 bned to be ddressed with smth else because sum 0 wont tell how many 0 available
        //convert 0 to -1
        
        vector<int>helper;
        int i=1;
        if(s[0] == '1') one_ct++;
        char curval=s[0];
        int cursize = 1;
        while(i<n){
            
            if(s[i] == '1')one_ct++;

            if(s[i] == curval){
                cursize++;
            }
            else{
                if(curval == '0') helper.push_back(cursize*-1);
                else helper.push_back(cursize*1);
                cursize=1;
                curval=s[i];
            }
            i++;
        }
        if(curval=='0')helper.push_back(cursize*-1);
        else helper.push_back(cursize*1);

        int fin_ans = one_ct;
        for(int j=1;j < helper.size() - 1;j++){ // first anmd last elemtn ebing set of positives doesnt help us as we can tranform them to 0s
            if(helper[j] > 0){
                fin_ans = max(fin_ans , one_ct + abs(helper[j-1]) + abs(helper[j+1]));
            }
        }
        return fin_ans;

    }
};