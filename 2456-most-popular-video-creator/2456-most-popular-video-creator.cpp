class Solution {
private:
    struct Info {
    long long totalViews;
    int maxViews;
    string bestId;
    };
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        vector<vector<string>>ans;
        unordered_map<string,Info>mp;
        for(int i=0;i<n;i++){
            string creator = creators[i];
            string id = ids[i];
            int view = views[i];
            if(mp.count(creator) == 0){
                mp[creator] = {view,view,id};
            }
            else{
                mp[creator].totalViews += view;

                int prev_max = mp[creator].maxViews;
                string prev_best_id = mp[creator].bestId;

                if(view>prev_max){
                    mp[creator].maxViews = view;
                    mp[creator].bestId=id;
                }
                else if(view == prev_max){
                    mp[creator].bestId = min(mp[creator].bestId , id);
                }

            }
        }

        long long mx =0;
        for(auto&p :mp){
            mx=max(mx , p.second.totalViews);
        }
        for(auto&p : mp){
            if(p.second.totalViews == mx){
                ans.push_back({p.first , p.second.bestId});
            }
        }
        return ans;
    }
};