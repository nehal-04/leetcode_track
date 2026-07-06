class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , [](const vector<int>&a , const vector<int>&b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            return a[1]>b[1];
        });

        int l=intervals[0][0];
        int h=intervals[0][1];
        int tot_ct=intervals.size();
        int rem_ct=0;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1] <= h){
                rem_ct++;
                continue;
            }
            else{
                l=intervals[i][0];
                h=intervals[i][1];
            }
        }
        return tot_ct - rem_ct;

        
    }
};