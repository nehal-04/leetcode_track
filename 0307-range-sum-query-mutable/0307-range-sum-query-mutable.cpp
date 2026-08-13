class NumArray {
private:
    void build(int idx , int l , int r , vector<int>&nums , vector<int>&seg){
        if(l == r){
            seg[idx] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        build(2*idx + 1 , l , mid , nums , seg);
        build(2*idx + 2 , mid+1 , r , nums , seg);
        seg[idx] = seg[2*idx +1] + seg[2*idx + 2];
        return;
    }

    void update_help(int idx , int low , int high , int index , int val , vector<int>&seg){
        
        if(low == high){
            seg[idx]=val;
            return;
            //we ar going straight to the base of the index value and in that case low == hight will occur 
        }

        int mid = low + (high - low )/2;
        if(index <=  mid){
            update_help(2*idx + 1, low , mid , index , val , seg);

        }
        else update_help(2*idx + 2 , mid+1 , high , index ,val , seg);

        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }

    int query_sum(int idx , int low , int high , int l , int r , vector<int>&seg){
        // l and r are origina query  andd low/high are for recursion 
        // obverlap then move else if low high completely inlusivethen use the value 

        if(low >= l && high <= r){
            return seg[idx];
        }

        if(low>r || high < l) return 0;
        int mid = low + (high - low )/2 ;
        int sideone = query_sum(2*idx + 1 , low , mid , l , r , seg);
        int sidetwo = query_sum(2*idx+2 , mid+1 , high , l , r , seg);
        return sideone + sidetwo;
    }


public:
    vector<int>seg;
    int sizeofseg = 0;
    int sizeofnums = 0;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4*n);
        sizeofseg = 4*n;
        sizeofnums = n;
        build(0,0,n-1,nums , seg);
    }
    
    void update(int index, int val) {
        update_help(0,0,sizeofnums-1 , index , val , seg);
    }
    
    int sumRange(int left, int right) {
        return query_sum(0, 0 , sizeofnums-1 , left , right , seg );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */