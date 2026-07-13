class Solution {
    int createnumber(int start , int length){
        int num=0;
        int d=start;
        int size=0;
        while(size<length){
            num=num*10 + d;
            d++;
            size++;
        }
        return num;


    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_dig =0 , high_dig=0;
        int temp_l=low;
        int temp_h=high;
        while(temp_l > 0){
            low_dig++;
            temp_l /=10;
        }
        while(temp_h > 0){
            high_dig++;
            temp_h /=10;
        }

        vector<int>ans;

        // i have digit list to go by 
        //iterate thru all possible elements of length low_dig to elemens of high_dig
        while(low_dig <=high_dig){
            int max_start = 10-low_dig;
            for(int i=1;i<=max_start;i++){
                int num = createnumber(i,low_dig);
                if(num >= low && num <=high) ans.push_back(num); 
            }
            low_dig++;
        }
        return ans;

        
    }
};