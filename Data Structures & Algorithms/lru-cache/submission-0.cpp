struct DLLNode {
    int value;
    DLLNode* next;
    DLLNode* prev;
} node;

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
            removeAndAdd(nodeRef[key]);
        } else {
            if (nodeRef.size() == capacity) {
                evict();
            }
            DLLNode* node = new DLLNode;
            node->value = key;
            node->prev=0;
            node->next=this->head;

            if (head == 0 && tail == 0) {
                this->head=node;
                this->tail=node;
            } else {
                this->head->prev = node;
                this->head=node;
            }
            
            nodeRef[key] = node;
        }
    }

    void removeAndAdd(DLLNode* x) {
        if (this->head == x && this->tail == x) {
            this->head=0;
            this->tail=0;
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

        if (head == 0 && tail == 0) {
            x->prev=0;
            x->next=0;
            this->head = x;
            this->tail=x;
        } else {
            x->prev = 0;
            x->next = head;
            this->head->prev=x;
            this->head = x;
        }

    }

    void evict() {
        int v = tail->value;
        DLLNode* t=this->tail;
        if (head == tail) {
            this->head=0;
            this->tail=0;
        } else {
            tail = tail->prev;
            tail -> next = 0;
        }
        
        nodeRef.erase(v);
        hashmap.erase(v);
        delete t;
    }
};
