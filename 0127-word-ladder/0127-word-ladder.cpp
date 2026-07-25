class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>word_bank;
        for(string s:wordList) word_bank.insert(s);//helps check easily if word present in wordList

        if(word_bank.count(endWord) == 0) return 0;

        unordered_set<string>visited;

        queue<string>q;

        q.push(beginWord);
        visited.insert(beginWord);
        int level=0;
        int word_size=beginWord.size();

        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                for(char ch: "abcdefghijklmnopqrstuvwxyz"){
                    for(int i=0;i<word_size;i++){
                        if(word[i] == ch) continue;
                        string neigh=word;
                        neigh[i]=ch;
                        if(visited.find(neigh) != visited.end()) continue;
                        if(word_bank.find(neigh) == word_bank.end()) continue;
                        if(neigh == endWord) return level+2;
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
            level++;   
        }
        return 0;

    }
};