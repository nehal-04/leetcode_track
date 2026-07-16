class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        if(k<arr[0] ) return k;
        if(arr[arr.size()-1] -arr.size() < k) return arr.size() + k;
        //base cases done
        int l = 0;
        int h= arr.size()-1 ;
        
        int ans=h; // ans is the index of first element with missing greater than equal to k
        while(l<=h){
            int mid_idx = l + (h-l)/2;
            if(arr[mid_idx] - (mid_idx+1) >= k){
                ans=mid_idx ;
                h=mid_idx-1;
            }
            else l=mid_idx+1;
        }
        int missingbeforeprev = arr[ans-1] - ans;
        return arr[ans-1] + k - missingbeforeprev;
        
    }
};