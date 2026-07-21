class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string>words1;
        vector<string>words2;
        
        string curword;
        curword += sentence1[0];
        for(int i=1;i<sentence1.size();i++){
            if(sentence1[i] == ' ') {
                words1.push_back(curword);
                curword="";
            }
            else{
                curword += sentence1[i];
            }
        }
        words1.push_back(curword);

        curword ="";
        curword += sentence2[0];
        for(int i=1;i<sentence2.size();i++){
            if(sentence2[i] == ' ') {
                words2.push_back(curword);
                curword="";
            }
            else{
                curword += sentence2[i];
            }
        }
        words2.push_back(curword);

        if(words1.size() > words2.size()) swap(words1,words2);//words1 always smaller 
        int l=0;
        while(l<words1.size() && words1[l] == words2[l])l++;
        //now l points to first index where match stop but number of words matched is idx+1 so we keep l as it is
        int r= 0;
        while(r < words1.size() - l && words1[words1.size()-1-r] == words2[words2.size()-1-r]) r++;

        return (l+r == words1.size());       
    }
};