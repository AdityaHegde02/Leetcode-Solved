class RandomizedSet {
public:
    unordered_map<int,int> map;
    vector<int> a;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.count(val) == 0){
            a.push_back(val);
            map[val] = a.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.count(val) != 0){
            int idx = map[val];
            int lastVal = a[a.size() - 1];
            swap(a[idx],a[a.size() - 1]);
            map[lastVal] = idx;
            a.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */