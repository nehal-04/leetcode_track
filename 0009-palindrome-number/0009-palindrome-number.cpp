class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long fin =0;
        int temp=x;
        while(x>0){
            int d = x % 10;
            fin = 1LL*(fin * 10 + d);
            x=x/10;
        }
        return fin==temp;
    }
};