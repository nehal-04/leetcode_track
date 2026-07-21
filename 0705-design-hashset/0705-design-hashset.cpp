class MyHashSet {
private:
    vector<vector<int>>v;
public:
    MyHashSet() {
        v.resize(1009);    
    }
    
    void add(int key) {
       int idx = key%1009 ;
       for(size_t i=0;i<v[idx].size();i++) {
        if(v[idx][i] == key) return;
       }
       v[idx].push_back(key); 
    }
    
    void remove(int key) {
        int idx = key%1009;
        for(size_t i =0 ; i < v[idx].size();i++){
            if(v[idx][i] == key){
                v[idx].erase(v[idx].begin() + i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = key%1009;
        for(size_t i=0;i<v[idx].size();i++){
            if(v[idx][i] == key) return true;
        }
        return false;

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */