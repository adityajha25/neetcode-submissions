class LRUCache:

    def __init__(self, capacity: int):
        self.capacity=capacity
        self.hashmap = {}
        self.nodeRefs={}
        self.head=None
        self.tail=None

    def get(self, key: int) -> int:
        if key in self.hashmap:
            self.removeAndAdd(self.nodeRefs[key])
            return self.hashmap[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            self.hashmap[key]=value
            self.removeAndAdd(self.nodeRefs[key])
        else:
            if len(self.hashmap) == self.capacity:
                self.evict()
            self.hashmap[key]=value
            node = DLLNode(key, None, None)
            if self.head is None and self.tail is None:
                self.head=node
                self.tail=node
            else:
                self.head.prev=node
                node.next=self.head
                self.head=node
            self.nodeRefs[key] = node
    
    def removeAndAdd(self, node: DLLNode):
        if self.head == node and self.tail == node:
            return
        elif self.head == node:
            self.head = self.head.next
            self.head.prev = None
        elif self.tail == node:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            node.prev.next = node.next
            node.next.prev = node.prev
        
        self.head.prev = node
        node.next=self.head
        self.head=node
        node.prev=None
    
    def evict(self):
        if self.head == self.tail:
            val = self.tail.value
            self.head=None
            self.tail=None
            del self.nodeRefs[val]
            del self.hashmap[val]
        else:
            val = self.tail.value
            self.tail.prev.next=None
            self.tail=self.tail.prev
            del self.nodeRefs[val]
            del self.hashmap[val]
            
        

class DLLNode:

    def __init__(self, value: int, next: DLLNode, prev: DLLNode):
        self.value=value
        self.next=next
        self.prev=prev