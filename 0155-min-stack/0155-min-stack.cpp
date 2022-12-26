class MinStack {
public:
    stack<int> st;
    map<int,int> mp;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int x  = st.top();
        if(mp[x]==1){
            mp.erase(x);
        }
        else{
            mp[x]--;
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return (mp.begin()->first);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */