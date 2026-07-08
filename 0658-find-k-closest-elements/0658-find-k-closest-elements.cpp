class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        int n=arr.size();
        for(int i=0;i<k;i++){
            pq.push({abs(arr[i] - x) ,  arr[i]});
        }

        for(int i=k;i<n;i++){
            int diff=abs(arr[i] - x);
            if(diff < pq.top().first || (diff==pq.top().first &&  arr[i] <pq.top().second) ){
                pq.pop();
                pq.push({diff , arr[i]});
            }
        }
        vector<int>ans(k);
        for (int i=0;i<k;i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};