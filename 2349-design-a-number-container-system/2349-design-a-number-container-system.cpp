class NumberContainers {
public:
    
    unordered_map<int,int> idx_to_num;
    unordered_map<int,set<int>> num_to_idx;

    NumberContainers() {

    }
    
    void change(int index, int number) {

        if (idx_to_num.count(index)) {
            int old = idx_to_num[index];
            num_to_idx[old].erase(index);
        }

        idx_to_num[index] = number;
        num_to_idx[number].insert(index);
    }
    
    int find(int number) {
        if(num_to_idx[number].size() > 0){
            return *num_to_idx[number].begin();
        }
        else return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */