class Solution {
private:
    string encode(vector<int>&cells){
        string ans="";
        for(int x:cells){
            ans += to_string(x);
        }
        return ans;
    }

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        // AS 64 possible states after the main state , if ay unsder some value , simulate lest cycle
        vector<int>temp(8,0);
        unordered_map<string,int>mp;
        int cur_idx=0;
        while(n>0){
            for(int i=1;i<=6;i++){
                temp[i] = (cells[i-1]==cells[i+1])?1:0;
            }

            cells=temp;
            n--;
            string s = encode(temp);
            if(mp.count(s)){
                int cyclestart = mp[s];
                int cyclelen= cur_idx - cyclestart;
                n %= cyclelen; //vvimp , main stwp
                if(n==0) return cells;
            }
            else mp[s]=cur_idx;
            
            cur_idx++;
        }
        return cells;

    }
};