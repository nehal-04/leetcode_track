class LFUCache {


struct NodeD{
    int key;
    int data;
    int freq;//to know which freq list to remove it from and add into its +1 or remove entirely
    NodeD* prev;
    NodeD* next;

    NodeD(int k , int val){
        key=k;
        data=val;
        freq=1;
        prev=nullptr;
        next=nullptr;
    }
};

struct DLL{
    NodeD* head ;
    NodeD* tail ;
    int size;

    DLL(){
        head = new NodeD(-1,-1);
        tail = new NodeD(-1,-1);
        head->next=tail;
        tail->prev = head;
        size=0;
    }
};


    int cap;
    int min_freq;
    unordered_map<int,NodeD*>key_node;
    unordered_map<int, DLL*> freq_dll;

private:
    void delete_node(NodeD* node){
        NodeD* temp=node;
        int f = node->freq;
        DLL* dll = freq_dll[f];
        
        NodeD* next_n = temp->next;
        NodeD* prev_n = temp->prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        next_n->prev = prev_n;
        prev_n->next = next_n;
        dll->size --;
    }

    void insert(NodeD* node , int freq , int val){
        if(freq_dll.count(freq)>0){
            DLL* dll = freq_dll[freq];
            NodeD* next_n = dll->head->next;
            dll->head->next = node;
            node->prev = dll->head;

            node->next=next_n;
            next_n->prev = node;
            dll->size++;
            if(val == -1) return;
            node->data = val;

        }
        else{
            freq_dll[freq] = new DLL();
            DLL * dll =freq_dll[freq];
            dll->head->next = node;
            node->prev = dll->head;

            dll->tail->prev=node;
            node->next = dll->tail;
            dll->size++; 
            if(val==-1) return;
            node->data = val;
        }
    }
public:

    LFUCache(int capacity) {
        cap=capacity;
        min_freq=0;
        
    }
    
    int get(int key) {
        if(key_node.find(key) == key_node.end()) return -1;
        NodeD* node = key_node[key];
        int freq= node->freq;

        delete_node(node);
        if(freq == min_freq && freq_dll[freq]->size==0) min_freq++;
        insert(node, freq+1 , -1);
        node->freq++;
        return node->data;
        
    }
    
    void put(int key, int value) {
        if(key_node.find(key) != key_node.end()){
            //node exists
            NodeD* node = key_node[key];
            int freq=node->freq;

            delete_node(node);
            if(freq == min_freq && freq_dll[freq] ->size == 0 ) min_freq++;
            insert(node,freq+1,value);
            node->freq++; 
        }
        else{
            //node not exist
            // case 1 , capacity not fully occupied
            //case 2 , capacity fully occupied
            NodeD* node= new NodeD(key , value );
            key_node[key]=node;
            if(cap>0){
                insert(node , 1 , value);
                cap--;
                min_freq=1;
            }
            else{

                // now evict from minfreq wala dll
                DLL* dll = freq_dll[min_freq];
                NodeD* n = dll->tail->prev;
                delete_node(n);
                key_node.erase(n->key);
                delete(n);

                insert(node , 1 , value);
                min_freq=1;
            }
            if(cap==0 && key_node.empty()) return;

        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */