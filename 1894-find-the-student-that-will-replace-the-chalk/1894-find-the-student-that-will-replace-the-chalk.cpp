class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long chalkusedinoneloop= 0;
        for(int x:chalk) chalkusedinoneloop += x;

        int neededchalk = k % chalkusedinoneloop;
        for(int i=0;i<chalk.size();i++){
            if(neededchalk < chalk[i]) return i;
            neededchalk -= chalk[i];
            
        }
        return chalk.size()-1;
        
    }
};