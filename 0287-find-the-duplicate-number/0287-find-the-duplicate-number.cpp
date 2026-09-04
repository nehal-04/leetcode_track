class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using binary search 
        // 1...n avail options of numbers and total numbers n+1 (indexed  0  ..... n)
        int r = nums.size() - 1;// this is the max possible number anyways
        int l = 1;
        //as array is not sorted we use the count idea
        while(l<r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int x : nums){
                if(x <= mid) cnt++;
            }
            if(cnt > mid) r=mid;
            else l=mid+1;
        }

        return l;
    }
};