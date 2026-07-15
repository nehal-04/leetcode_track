class Solution {
private:
    long long dist(int x , int y){
        long long x_thing = 1LL*pow(x,2);
        long long y_thing = 1LL*pow(y,2);
        return x_thing + y_thing;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>>pq;
        for(int i=0 ; i<points.size();i++){
            int x_coord = points[i][0];
            int y_coord = points[i][1];
            if(i < k) pq.push({dist(x_coord,y_coord) , {x_coord , y_coord}});
            else{
                long long top_val = pq.top().first;
                if(dist(x_coord , y_coord)  < top_val){
                    pq.pop();
                    pq.push({dist(x_coord , y_coord) , { x_coord , y_coord}});
                }
            }
        }    

        vector<vector<int>>ans;
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y= pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;

    }
};