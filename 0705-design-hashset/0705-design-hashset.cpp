class MyHashSet {
public:
    vector<int> arr;
    
    MyHashSet() {
        for(int i = 0; i <= 1000000; i++){
            arr.push_back(0);
        }
    }
    
    void add(int key) {
        arr[key]++;
    }
    
    void remove(int key) {
        if(arr[key]){
            arr[key] = 0;
        }
    }
    
    bool contains(int key) {
        return (arr[key]);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */