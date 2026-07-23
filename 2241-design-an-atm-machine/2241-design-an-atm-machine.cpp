class ATM {
public:
    vector<int>total_count;
    ATM() {
        total_count = {0,0,0,0,0};
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            if(banknotesCount[i] > 0){
                total_count[i] += banknotesCount[i];
            }
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        vector<int>notes = {20,50,100,200,500};
        for(int i=4;i>=0;i--){
            ans[i] = min(amount/notes[i] , total_count[i]);
            amount -= ans[i] * notes[i];
        }
        if(amount == 0){
            for(int i=0;i<5;i++){
                total_count[i] -= ans[i];
            }
            return ans;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */