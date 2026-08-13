class FreqStack {
private:
    int max_freq;
    unordered_map<int , int > freq;
    vector<vector<int>>groups;
public:
    FreqStack() {
        max_freq=0;
        groups.resize(20000); // as 2*10 power 4 pushes possible

    }
    
    void push(int val) {
        if(freq.find(val) == freq.end()){
            // new element
            freq[val] = 1;
            groups[1].push_back(val);
            max_freq=max(max_freq,1);
        }
        else{
            int f = freq[val];
            freq[val]++;
            groups[f+1].push_back(val);
            max_freq=max(max_freq,f+1);
        }
    }
    
    int pop() {
        int val = groups[max_freq].back();
        groups[max_freq].pop_back();

        freq[val]--;
        if(groups[max_freq].size() == 0) max_freq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */