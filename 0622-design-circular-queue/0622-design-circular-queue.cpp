class MyCircularQueue {
public:
    vector<int> queue;
    int K;
    
    MyCircularQueue(int k) {
        K = k;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            queue.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            queue.erase(queue.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty()){
            return queue.front();
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()){
            return queue.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return queue.size() == 0;
    }
    
    bool isFull() {
        return queue.size() == K; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */