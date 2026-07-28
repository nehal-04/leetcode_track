class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>>helper(n);
        for(int i=0;i<n;i++){
            helper[i] = {aliceValues[i] + bobValues[i] , i};
        }
        sort(helper.begin(),helper.end(),greater<pair<int,int>>());
        
        int alice_sum =0;
        int bob_sum =0;
        for(int i=0;i<n;i++){
            if(i%2==0) alice_sum += aliceValues[helper[i].second];
            else bob_sum += bobValues[helper[i].second];
        }
        if(bob_sum>alice_sum) return -1;
        else if(alice_sum > bob_sum) return 1;
        return 0;
        
    }
};