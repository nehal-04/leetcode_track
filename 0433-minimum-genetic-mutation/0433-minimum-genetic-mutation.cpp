class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool found =false;
        unordered_set<string>bank_set;//to help check fast if a word present in bank
        for(string s : bank){
            if(s == endGene) {
                found = true;
            }
            bank_set.insert(s);
        }
        if(!found) return -1;
        //special case handled

        unordered_set<string>visited;

        queue<string>q;

        q.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                if(word == endGene) return level;
                //now simulate all word chhanegs for each a c g t 
                for(char ch : "ACGT"){
                    for(int i=0;i<8;i++){
                        string neigh = word;
                        neigh[i] = ch;  // first try wih A then C then G then T
                        if(visited.find(neigh) != visited.end())continue;
                        if(bank_set.find(neigh) == bank_set.end()) continue;
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
            
            level++;
        }
        return -1;




    }
};