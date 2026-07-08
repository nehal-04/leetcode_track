class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> numswithindices;
        for(int i=0;i<nums.size();i++){
            numswithindices.push_back({nums[i] , i});
        }

        sort(numswithindices.begin() , numswithindices.end() , [](const pair<int,int>&a , const pair<int,int>&b){
            return a.first>b.first;
        });

        vector<pair<int,int>>topk(k);
        for(int i=0;i<k;i++){
            topk[i] = numswithindices[i];
        }

        sort(topk.begin() , topk.end() , [](const pair<int,int>&a , const pair<int,int> &b){
            return a.second < b.second;
        });

        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(topk[i].first);
        }
        return result;



        
    }
};