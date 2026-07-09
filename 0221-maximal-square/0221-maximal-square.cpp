class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>prev(cols+1,0);
        vector<int>curr(cols+1,0);

        int maxans=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(matrix[i-1][j-1] == '0'){
                    curr[j]=0;
                    continue;
                }
                curr[j] = min({curr[j-1] , prev[j] , prev[j-1]}) + 1;
                maxans = max(maxans , curr[j]); 
            }
            prev=curr;
        }
        return maxans * maxans;

    }
};