class LRUCache {
    // Method 1 [BruteForce using arrays] O(N), O(N) difficult to explain to interviewer, interviewer won't even ask that

    // Method 2 [Hashmap, Doubly LinkedList, STRIVER] O(1), O(2N)
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode) {
        m[newnode->key] = newnode;
        newnode->next = head->next;
        newnode->next->prev = newnode;
        newnode->prev = head;
        head->next = newnode;
    }

    void deleteNode(node* delnode) {
        m.erase(delnode->key);
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* resnode = m[key];
            deleteNode(resnode);
            addNode(resnode);
            return resnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) deleteNode(m[key]);
        if(m.size()==cap) deleteNode(tail->prev);
        addNode(new node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */