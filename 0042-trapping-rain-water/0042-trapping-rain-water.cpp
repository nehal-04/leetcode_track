class Solution {
private:
    void makemaxtoright(vector<int>&height , vector<int>&arr){
        arr[height.size()-1] = height[height.size()-1];
        int max_to_right= height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            arr[i]= max_to_right;
            max_to_right = max(height[i] , max_to_right);
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total=0;
        int max_to_left = height[0];
        vector<int>arr(n,0);
        makemaxtoright(height,arr);

        for(int i=1;i<n;i++){

            if(height[i] >= max_to_left || height[i] >= arr[i]) {
                max_to_left = height[i];
                continue;
            }

            int val_added = min(arr[i], max_to_left) - height[i];
            total += val_added;
            max_to_left = max(max_to_left , height[i]);
        
        }
        return total;
        
        
    }
    
};