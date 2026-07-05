class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>extra;
        for(int x:nums){
            extra.push_back(to_string(x));
        }
        sort(extra.begin(),extra.end() , [](string&a , string&b){
            return a+b >b+a;
        });
        string ans="";
        if(extra[0]=="0") return "0";
        for(int i=0;i<extra.size();i++){
            ans += extra[i];
        }
        return ans;
    }
};