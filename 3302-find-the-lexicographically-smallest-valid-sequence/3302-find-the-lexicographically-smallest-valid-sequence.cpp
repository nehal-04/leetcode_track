class Solution {

public:
    vector<int> validSequence(string word1, string word2) {
        int n = word2.size();
        vector<int>wordsmatchingtoright(word1.size()+1);
        wordsmatchingtoright[word1.size()] =0;
        int j=word2.size()-1;
        int curr_match = 0;
        for(int i=word1.size()-1;i>=0;i--){
            if(j<0){
                 wordsmatchingtoright[i]=curr_match ; 
                continue;
            }
            if(word1[i] == word2[j]){
                curr_match++;
                j--;
            }
            wordsmatchingtoright[i]=curr_match;
        }

        vector<int>ans;
        int i=0;
        j=0;
        bool changepower=true;
        while(i<word1.size() && j < word2.size()){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                i++;
                j++;
                continue;
            }

            if(changepower &&  wordsmatchingtoright[i+1] >= word2.size()-j -1){
                changepower = false;
                ans.push_back(i);
                i++;
                j++;
                continue;
            }
            i++;

        }

        if(ans.size() != word2.size()) return {};
        return ans;

        
        
    }
};