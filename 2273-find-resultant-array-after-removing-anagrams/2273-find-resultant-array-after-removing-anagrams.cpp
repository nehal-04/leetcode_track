class Solution {
private:
    bool validanagram(string word1 , string word2){
        // if word 2 is anagram of word 1
        if(word1.size() != word2.size()) return false;
        vector<int>freq(26,0);
        for(char c:word1) freq[c-'a']++;

        for(char c: word2){
            if(freq[c-'a'] == 0) return false;
            freq[c-'a']--;
        }
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int size = words.size();
        if(size<=1) return words;
        int curr=1;
        int prev=0;
        vector<string>ans;
        while(curr<size){
            if(!validanagram(words[curr] , words[prev])){
                ans.push_back(words[prev]);
                prev=curr;
            }
            curr++;
        }
        ans.push_back(words[prev]);
        return ans;

        
    }
};