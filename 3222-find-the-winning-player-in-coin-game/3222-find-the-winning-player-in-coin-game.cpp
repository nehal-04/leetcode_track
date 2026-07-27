class Solution {
public:
    string winningPlayer(int x, int y) {

        int ctr=1;
        while(x>0 && y>0){
            x--;
            y-=4;
            if(x<0 || y<0) break;
            ctr++;
        }
        if(ctr%2==1) return "Bob";
        else return "Alice";
    }
};