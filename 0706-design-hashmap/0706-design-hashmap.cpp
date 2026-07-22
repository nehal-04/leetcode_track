class MyHashMap {
public:
    vector<vector<pair<int,int>>>v; //key:value
    int size = 10000;

    MyHashMap() {
        v.resize(size);
    }
    
    void put(int key, int value) {
        int k = key % size;
        for(auto& p:v[k]){
            if(p.first == key){
                p.second=value;
                return;
            }
        }
        v[k].push_back({key,value});
    }
    
    int get(int key) {
        int k = key % size;
        for(auto & p : v[k]){
            if(p.first==key) return p.second;
        }
        return -1;

    }
    
    void remove(int key) {
        int k=key%size;
        int idx = 0;
        bool check = false;
        for(auto & p:v[k]){
            if(p.first==key){
                check = true;
                break;
            }    
            idx++;
        }
        if(check){
            v[k].erase(v[k].begin() + idx);
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */