class Spreadsheet {
private:
    int getvaluehelper(string s , vector<vector<int>>&grid){
        if(s[0] >='A' && s[0] <='Z'){
            //case of grid 
            int col = s[0]-'A';
            int row = stoi(s.substr(1)) -1;
            return grid[row][col];
        }
        return stoi(s);
    }
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.resize(rows , vector<int>(26 , 0));
    }
    
    void setCell(string cell, int value) {
        char c = cell[0];
        int col = c-'A';
        int row = stoi(cell.substr(1)) - 1;//-1 as we have implmeneted 0 indexed and provided input is 1 indexed
        grid[row][col]=value;

    }
    
    void resetCell(string cell) {
        char c = cell[0];
        int col = c-'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col]=0;
    }
    
    int getValue(string formula) {
        formula=formula.substr(1);
        vector<string>operands;
        string curoperand="";
        for(int i=0;i<formula.size();i++){
            if(formula[i] == '+'){
                operands.push_back(curoperand);
                curoperand="";
                continue;
            }
            curoperand += formula[i];
        }
        operands.push_back(curoperand);
        //separated out
        int ans=0;
        for(string s:operands){
            ans += getvaluehelper(s,grid);
        }
        return ans;


        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */