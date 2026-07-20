class Solution {
private :
    bool validanagram(string word1 , string word2){
        // IF WORD 2 IS ANAGRAM OF WORD 1
        if(word1.size() != word2.size()) return false;
        vector<int>freq(26,0);
        for(char c: word1){
            freq[c-'a']++;
        }
        for(char c : word2){
            if(freq[c-'a'] == 0) return false;
            freq[c-'a']--;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>ans;
        unordered_map<string , vector<string>>mp;
        int word_ct = strs.size();
        for(int i=0;i<word_ct;i++){
            string word = strs[i];
            sort(word.begin() , word.end());
            mp[word].push_back(strs[i]);
        }
        
        vector<string>curset;
        for(pair<string , vector<string>>p : mp){
            for(string s:p.second) curset.push_back(s);
            ans.push_back(curset);
            curset.clear();
        }
        return ans;
        
    }
};