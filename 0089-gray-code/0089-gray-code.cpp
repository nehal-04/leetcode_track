class Solution {
private :
    int decimalrep(string s){
        int n =s.size();
        int val=0;
        int i= n-1;
        int multiplier=1;
        while(i>=0){
            if(s[i] == '1'){
                val += multiplier;
            } 
            multiplier *=2;
            i--;
        }
        return val;
    }
    vector<string> generategc(int n ){
        if(n==1) return {"0","1"};

        vector<string> gc_minus_one = generategc(n-1);
        vector<string> mirrored;

        for(int i= gc_minus_one.size()-1 ; i>=0 ; i--){
            mirrored.push_back(gc_minus_one[i]);
        }

        vector<string> new_nodes;
        for(int i=0;i<gc_minus_one.size();i++){
            new_nodes.push_back("0" + gc_minus_one[i]);
        } 

        for(int i=0;i<mirrored.size();i++){
            new_nodes.push_back("1" + mirrored[i]);
        }

        return new_nodes;

    }
public:
    vector<int> grayCode(int n) {
        vector<string>ans = generategc(n);
        vector<int>fin_ans;
        for(int i=0;i<ans.size();i++){
            fin_ans.push_back(decimalrep(ans[i]));
        }

        return fin_ans;
    }
};