class MyCircularDeque {
public:
    vector<int> deque;
    int mxSize;
    
    MyCircularDeque(int k) {
        mxSize = k;
    }
    
    bool insertFront(int value) {
        if(!isFull()){
            deque.insert(deque.begin(),value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull()){
            deque.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty()){
            deque.erase(deque.begin());
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty()){
            deque.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(!isEmpty()){
            return deque.front();
        }
        return -1;
    }
    
    int getRear() {
        if(!isEmpty()){
            return deque.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return (deque.size() == 0);
    }
    
    bool isFull() {
        return (deque.size() == mxSize);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */