class LRUCache {
struct NodeD{
    int data;
    int key;
    NodeD* next;
    NodeD* prev;

    NodeD(int k , int val){
        data=val;
        key = k;
        next=nullptr;
        prev=nullptr;
    }

    NodeD(int val , int k ,NodeD* n , NodeD* p){
        data=val;
        key=k;
        next=n;
        prev=p;
    }
};


    unordered_map<int,NodeD*>mp; // key : Node* reference
    int cap;
    NodeD* head;
    NodeD* tail;
private:
    void deletionofnode(NodeD* node){
        NodeD* temp = node;
        NodeD* back = node->prev;
        NodeD* front = node->next;
        temp->prev=nullptr;
        temp->next=nullptr;
        //no edge cases as we will keep dummy head and tail so back and front can never be nullptrr
        back->next=front;
        front->prev=back;
        return;
    }

    void insert(NodeD* node , int val){
        NodeD* temp = head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        if(val==-1) return ; 
        node->data = val;
    }


public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new NodeD(-1,-1);
        tail = new NodeD(-1,-1);
        head->next=tail;
        tail->prev=head;    
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        NodeD* node= mp[key];
        deletionofnode(node);
        insert(node,-1);
        return node->data;
    }
    
    void put(int key, int value) {
        //in case not present in map
        if(mp.find(key) != mp.end()){
            //here no extra element so no need to pop out lru , just re arange dll
            NodeD* node = mp[key];
            deletionofnode(node);
            if(value == node->data) insert(node,-1);
            else insert(node,value);
        }
        else{
            //now new element , now 2 cases if size of mp == capacity or not
            NodeD* node = new NodeD(key , value);  
            if(mp.size() == cap){
                NodeD* popped=tail->prev;
                int del_k = popped->key;
                mp.erase(del_k);
                deletionofnode(popped);
                delete(popped);
                insert(node , value);
                mp[key]=node;

            }
            else{
                insert(node,value);
                mp[key]=node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */