class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // range 1950-2050
        vector<int>indiff(102,0);
        for(vector<int>&v : logs){
            int b_year = v[0];
            int d_year = v[1];
            b_year -= 1950;
            d_year -= 1950;
            indiff[b_year] +=1;
            indiff[d_year] -= 1;

        }
        int cur_sum = 0;
        int max_pop = 0;
        int max_pop_year = 0;
        for(int i=0;i<102;i++){
            cur_sum += indiff[i];
            if(cur_sum > max_pop){
                max_pop = cur_sum;
                max_pop_year = 1950 + i;
            }
        }

        return max_pop_year;
    }
};