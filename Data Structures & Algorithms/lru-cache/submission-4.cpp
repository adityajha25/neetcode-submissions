struct DLLNode {
    int value;
    DLLNode* next;
    DLLNode* prev;
};

class LRUCache {

private:
    int capacity;
    std::unordered_map<int, int> hashmap;
    std::unordered_map<int, DLLNode*> nodeRef;
    DLLNode* head;
    DLLNode* tail;
    //head has most recent, tail has least recent

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->hashmap={};
        this->nodeRef={};
        this->head=0;
        this->tail=0;
    }
    
    int get(int key) {
        if (hashmap.contains(key)) {
            removeAndAdd(nodeRef[key]);
            return hashmap[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        hashmap[key]=value;
        if (nodeRef.contains(key)) {
            //it's an update, but access order still should be updated
            removeAndAdd(nodeRef[key]);
        } else {
            //evict if at capacity before adding new item
            if (nodeRef.size() == capacity) {
                evict();
            }
            DLLNode* node = new DLLNode;
            node->value = key;
            node->prev=0;
            node->next=0;
            
            //2 cases for adding new node: first node (this will be) or nodes already exist, add at head
            if (head == 0 && tail == 0) {
                this->head=node;
                this->tail=node;
            } else {
                this->head->prev = node;
                node->next=this->head;
                this->head=node;
            }
            
            nodeRef[key] = node;
        }
    }

    void removeAndAdd(DLLNode* x) {
        //4 cases of remove:
        /*
        1. 1 node only
        2. head
        3. tail
        4. from middle, update pointers both ways
        */
        if (this->head == x && this->tail == x) {
            //in the case that 1 node only, you'd be removing and adding same node back, so don't do anything
            return;
        }
        else if (this->head == x) {
            head = head -> next;
            head -> prev = 0;
        } else if (this->tail == x) {
            tail = tail->prev;
            tail -> next = 0;
        } else {
            DLLNode* a = x->prev;
            DLLNode* b = x->next;
            a->next = b;
            b->prev = a;
        }

        /*
        adding nodes: 2 cases:
        1. this is the only node, add to head and tail
        2. add to head, make sure node's prev is 0, because it could have came from middle and is pointing to something else
        */

        x->prev = 0;
        x->next = head;
        this->head->prev=x;
        this->head = x;
        

    }

    void evict() {
        /*
        1. 2 cases: first is if the head is the tail, so one node only
        2. evict tail directly, make sure to update the tail
        */
        int v = tail->value;
        DLLNode* t=this->tail;
        if (head == tail) {
            this->head=0;
            this->tail=0;
        } else {
            tail = tail->prev;
            tail -> next = 0;
        }
        
        //update the hashmaps too
        nodeRef.erase(v);
        hashmap.erase(v);
        delete t;
    }
};
