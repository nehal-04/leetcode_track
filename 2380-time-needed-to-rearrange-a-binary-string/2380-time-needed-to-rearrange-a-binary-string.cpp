class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int prev_fin =-1;
        int fin_fin=0;
        int zeroes=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '0') zeroes++;
            else if(zeroes>0) {
                fin_fin = max(zeroes , prev_fin + 1);
                prev_fin = fin_fin;
            }
        }
        return fin_fin;

        
    }
};