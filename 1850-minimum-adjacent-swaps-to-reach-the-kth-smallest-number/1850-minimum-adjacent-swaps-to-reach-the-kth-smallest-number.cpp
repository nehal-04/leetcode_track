class Solution {
private:
    string nextpermutation(string num){
        int n = num.size();
        int piv=n-2;
        while(piv>=0 && num[piv] >= num[piv+1]) piv--;
        //handle later case when fully derteasing number
        int r=n-1;
        int reqd_idx=n-1;
        while(r>piv){
            if(num[r] <= num[piv]) r--;
            else{
                reqd_idx=r;
                break;
            }            
        }
        swap(num[piv] , num[reqd_idx]);
        reverse(num.begin() + piv + 1 , num.end());
        return num;
    }
    int getswaps(string num1 , string num2){
       int ans = 0;
       for(int i=0;i<num2.size();i++){
        if(num1[i] == num2[i]) continue;
        int j = i;
        while(j<num1.size() && num1[j] != num2[i])j++;
        while(j>i){
            swap(num1[j],num1[j-1]);
            ans++;
            j--;
        }
       }
       return ans;
    }
public:
    int getMinSwaps(string num, int k) {

        string finalnumber= num;
        for(int i=0;i<k;i++){
            finalnumber = nextpermutation(finalnumber);
        }
        //now how do i calculate min swaps in two numbers
        return getswaps(num , finalnumber);
    }
};