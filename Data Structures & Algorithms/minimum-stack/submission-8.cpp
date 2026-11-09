class MinStack {

private: 
    vector<int> backing_array;
    vector<int> min_pointers;
    int min_seen;
public:
    MinStack() {
        min_seen = INT_MAX;
    }
    
    void push(int val) {
        if (val < min_seen){
            min_seen = val;
        }
        backing_array.push_back(val);
        min_pointers.push_back(min_seen);
    }
    
    void pop() {

        if (backing_array.size() >= 1) {
            backing_array.pop_back();
            min_pointers.pop_back();
        }
        
        if (backing_array.size() >= 1) {
            min_seen = min_pointers.back();
        } else {
            min_seen = INT_MAX;
        }
    }
    
    int top() {
        return backing_array.back();
    }
    
    int getMin() {
        return min_seen;
    }
};
