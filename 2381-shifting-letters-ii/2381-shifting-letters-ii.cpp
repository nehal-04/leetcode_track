class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n1 = s.size();
        int n2 = shifts.size();

        vector<int>diff_arr(n1 , 0);
        for(vector<int>& shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int val = shift[2];
            diff_arr[start] += (val == 1)? 1 : -1;
            if(end + 1 < n1) diff_arr[end + 1] += (val==1) ? -1 : 1; 
        }

        vector<int>final_shifts(n1,0);
        int cur_shift = 0;
        for(int i =0;i<n1;i++){
            cur_shift += diff_arr[i];
            final_shifts[i]=cur_shift;
        }

        string ans =s ;
        for(int i=0;i<n1;i++){
            int x = s[i] - 'a';
            x += final_shifts[i];
            x= x%26;
            if(x<0) x=x+26;
            x = x % 26;
            ans[i] = 'a' + x;
        }
        return ans;



    }
};