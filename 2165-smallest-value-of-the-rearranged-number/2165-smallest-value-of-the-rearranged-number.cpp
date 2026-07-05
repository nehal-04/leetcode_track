class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        vector<int>helper;
        bool neg_check = false;
        if(num < 0){
            neg_check = true;
            num = -num;
        }
        while(num>0){
            int d=num%10;
            helper.push_back(d);
            num = num/10;
        }


        if(neg_check == false){
            sort(helper.begin(),helper.end());
            if(helper[0]==0){
                int firstNonZero = 0;

                while(firstNonZero < helper.size() && helper[firstNonZero] == 0)
                    firstNonZero++;

                swap(helper[0], helper[firstNonZero]);
            }
            
            long long ans=0;
            for(int i=0;i<helper.size();i++){
                ans = ans*10 + helper[i];
            }
            return ans;

        }
        else{
            sort(helper.begin() , helper.end());
            reverse(helper.begin() , helper.end());
            long long ans=0;
            for(int i=0;i<helper.size();i++){
                ans = ans*10 + helper[i];
            }
            return ans*-1;
        }   
        







        
    }
};