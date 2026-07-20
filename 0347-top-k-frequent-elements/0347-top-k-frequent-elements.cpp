class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        
        for(int x : nums){
            mp[x]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

        int ctr=0;
        for(pair<int,int>p : mp){
            int el = p.first;
            int freq= p.second;
            
            if(ctr< k){
                pq.push({freq , el});
            }
            else{
                if(pq.top().first < freq){
                    pq.pop();
                    pq.push({freq,el});
                }
            }
            ctr++;
            
        }

        vector<int>ans;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;



        
    }
};