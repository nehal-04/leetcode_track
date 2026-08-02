class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
     
      unordered_map<int,int> freq;
      for(int x: nums) freq[x]++;
     int res=0;
      for(auto it: freq) {
        if(it.second==2){ 
          res^=it.first;
        }
      }
      return res;
       }
};