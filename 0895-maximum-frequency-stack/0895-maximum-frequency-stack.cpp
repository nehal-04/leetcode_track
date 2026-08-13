class FreqStack {
private:
    int max_freq;
    stack<int>st1;
    stack<int>st2;

    unordered_map<int,int>key_freq;
    unordered_map<int,int>freq_count;
public:
    FreqStack() {
        max_freq=0;
    }
    
    void push(int val) {
        if(key_freq.find(val) == key_freq.end()){
            //first element occurence in stack
            key_freq[val]=1;
            max_freq = max(max_freq , 1);
            freq_count[1]++;
        }
        else{
            key_freq[val] ++;
            freq_count[key_freq[val] -1] --;
            freq_count[key_freq[val]]++;
            max_freq = max(max_freq , key_freq[val]);
        }
        st1.push(val);
    }
    
    int pop() {
        int ans ;
        while(!st1.empty()){
            int node=st1.top();
            st1.pop();
            if(key_freq[node] != max_freq) st2.push(node);
            else{
                freq_count[max_freq]--;
                key_freq[node]--;
                freq_count[key_freq[node]]++;

                if(freq_count[max_freq] == 0){
                    max_freq--;
                }                
                ans=node;
                break;
            }
        }
        while(!st2.empty()){
            int nde = st2.top();
            st2.pop();
            st1.push(nde);
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */