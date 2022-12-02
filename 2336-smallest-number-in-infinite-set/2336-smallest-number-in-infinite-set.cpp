class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    unordered_set<int> s;
    
    SmallestInfiniteSet() {
        for(int i = 0; i < 1002; i++){
            minheap.push(i + 1);
            s.insert(i + 1);
        }
    }
    
    int popSmallest() {
        int top = minheap.top();
        minheap.pop();
        s.erase(top);
        return top;
    }
    
    void addBack(int num) {
        if(s.find(num) == s.end()){
            s.insert(num);
            minheap.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */