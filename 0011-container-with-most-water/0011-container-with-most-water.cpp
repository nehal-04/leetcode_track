class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int l=0;
        int r=n-1;
        int max_ans =0;
        while(l<=r){
            int val = (r-l) * min(height[l] , height[r]);
            max_ans = max(val , max_ans);
           if(height[l] <= height[r]) l++;
           else r--;
        }
        return max_ans;
        
    }
};