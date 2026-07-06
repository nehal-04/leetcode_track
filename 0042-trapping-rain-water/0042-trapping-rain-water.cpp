class Solution {
private:
    void makenge(vector<int>&height , vector<int>&arr){
        arr[height.size()-1]=height[height.size()-1];
        int max_to_right = height[height.size()-1];
        bool check=false;
        int val;
        for(int i=height.size()-2;i>=0;i--){
            if(height[i]>max_to_right) {check=true;val=height[i];}
            arr[i]=max_to_right;
            if(check){
                max_to_right=val;
                check=false;
            };
        }


        
    }
public:
    int trap(vector<int>& height) {
        
        int prefix_max=height[0];
        int tot_water=0;
        vector<int>next_max_right(height.size());
        makenge(height,next_max_right);

        for(int i=1;i<height.size()-1;i++){
            int water_added = min(next_max_right[i] , prefix_max) -height[i];
            if(water_added > 0 ) tot_water += water_added;
            prefix_max=max(prefix_max , height[i]);
        }
        return tot_water;

        
    }
};