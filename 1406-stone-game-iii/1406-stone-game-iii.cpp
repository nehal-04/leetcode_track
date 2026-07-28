class Solution {
private:
    vector<vector<int>>mem_help{2 , vector<int>(5*(1e4) , -1)};
    int finalhelper(int cur_stone , int player , vector<int>&stoneValue){
        int n= stoneValue.size();
        if(cur_stone >= n) return 0;
        int res = (player == 1) ? INT_MIN : INT_MAX;
        int running_value=0;

        if(mem_help[player][cur_stone] != -1) return mem_help[player][cur_stone];
        
        for(int i=0;i<3;i++){
            if(cur_stone + i >= n) break;
            if(player == 1){
                //alice
                
                running_value += stoneValue[cur_stone + i];

                res = max(res , running_value + finalhelper(cur_stone + i + 1, 0 , stoneValue));
            }
            else{
                //bob
                running_value -= stoneValue[cur_stone + i];
                res = min(res , running_value + finalhelper(cur_stone + i + 1 , 1 , stoneValue));
            }
        }
        return mem_help[player][cur_stone] = res;

    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = finalhelper(0, 1,stoneValue);
        if(ans>0) return "Alice";
        else if(ans < 0) return "Bob";
        else return "Tie";    
    }
};