class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        
        Node*next = NULL;
        Node*prev = NULL;
        
        Node(int key, int value){
            this->key = key;
            this->value = value;
        }
    };
    
    void addNode(Node* n){
        Node*temp = head->next;
        n->next = temp;
        n->prev = head;
        head->next = n;
        temp->prev = n;
        return;
    }
    
    void deleteNode(Node* n){
        Node*prevNode = n->prev;
        Node*nextNode = n->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        return;
    }
    
    Node*head = new Node(-1, -1);
    Node*tail = new Node(-1, -1);
    
    int cap;
    unordered_map<int, Node*> mapp;
    
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mapp.find(key) != mapp.end()){
            Node*n = mapp[key];
            int res = n->value;
            mapp.erase(key);
            deleteNode(n);
            addNode(n);
            mapp[key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mapp.find(key) != mapp.end()){
            Node*existingNode = mapp[key];
            mapp.erase(key);
            deleteNode(existingNode);
        }
        
        if(mapp.size() == cap){
            mapp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key, value));
        mapp[key] = head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */