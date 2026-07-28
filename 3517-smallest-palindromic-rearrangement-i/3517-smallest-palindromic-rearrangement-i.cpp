class Solution {
public:
    string smallestPalindrome(string s) {
        //keep freq track
        int n = s.size();
        bool odd_l=false;
        if(n%2 != 0 ) odd_l = true;
        //guaranteed already palindrormic
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }

        // if odd_l = false;
        string ans ="";
        char ch;
        for(int i=0;i<26;i++){
            if(freq[i] >= 2){
                for(int j=0;j<freq[i]/2 ;j++) ans += 'a'+i;
            }
            if(freq[i] %2 != 0)ch = 'a'+i;
        }
        
        string ans2=ans;
        reverse(ans2.begin() , ans2.end());
        if(!odd_l) ans += ans2;
        else {
            ans += ch;
            ans += ans2;
        }

        return ans;


        
    }
};