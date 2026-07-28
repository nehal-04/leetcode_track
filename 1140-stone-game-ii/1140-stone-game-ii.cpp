class Solution {
private:
    vector<vector<vector<int>>> memoization_help {2, vector<vector<int>>(101 , vector<int>(101,-1))};
    int solveforalice(int idx , int m , int player , vector<int>&piles){
        //returns max stones alie can get
        int n = piles.size();
        if(idx >=n) return 0;
        int stones =0;
        int result = (player==1) ? -1 : INT_MAX;
        
        if( memoization_help[player][idx][m] !=-1) return memoization_help[player][idx][m];
        
        for(int x =1 ;x<=2*m; x++){
            if(idx+x-1 >=n) break;
            stones += piles[idx+x-1];
            
            if(player == 1){
                //Alice
                result = max(result , stones + solveforalice(idx+x , max(m,x) , 0 , piles)) ;

            }
            else{

                result = min(result,solveforalice(idx+x , max(m,x) , 1 , piles));

            }
        }

        return memoization_help[player][idx][m] = result;

    }
public:
    int stoneGameII(vector<int>& piles) {
        return solveforalice(0,1,1,piles);
    }
};