class KthLargest {
public:
    int k_store=0;
    vector<int> storage;

    KthLargest(int k, vector<int>& nums) {
        storage = nums;
        make_heap(storage.begin(), storage.end());
        k_store=k;
    }
    
    int add(int val) {
        storage.push_back(val);
        make_heap(storage.begin(), storage.end());
        vector<int> temp;
        while (temp.size() < k_store) {
            pop_heap(storage.begin(),storage.end());
            int x=storage.back();
            storage.pop_back();
            temp.push_back(x);
        }
        int ret = temp.back();
        while (temp.size() > 0){
            storage.push_back(temp.back());
            temp.pop_back();
        }
        make_heap(storage.begin(),storage.end());
        return ret;
    }
};
