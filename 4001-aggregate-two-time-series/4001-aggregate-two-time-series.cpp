class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        int ptr1 = 0;
        int ptr2 = 0;
        int s1 = series1.size();
        int s2 = series2.size();
    
        vector<vector<int>>ans;
    
        while(ptr1<s1 && ptr2 <s2){
            if(series1[ptr1][0] < series2[ptr2][0] ){
                int sum_here = series1[ptr1][1] + series2[ptr2][1];
                ans.push_back({series1[ptr1][0] , sum_here });
                ptr1++;
            }
            else if(series2[ptr2][0] < series1[ptr1][0]){
                int sum_here= series1[ptr1][1] + series2[ptr2][1];
                ans.push_back({series2[ptr2][0] , sum_here });
                ptr2++;
            }
            else{
                int sum_here = series1[ptr1][1] + series2[ptr2][1];
                ans.push_back({series2[ptr2][0] , sum_here});
                ptr1++;
                ptr2++;
            }
        }
        while(ptr1 < s1){
            ans.push_back({series1[ptr1][0] , series1[ptr1][1]});
            ptr1++;
        }

        while(ptr2 < s2){
            ans.push_back({series2[ptr2][0] , series2[ptr2][1]});
            ptr2++;
        }

        return ans;

    }
};