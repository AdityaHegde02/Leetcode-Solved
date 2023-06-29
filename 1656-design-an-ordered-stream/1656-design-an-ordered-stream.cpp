class OrderedStream {
public:
    vector<string> order;
    int idx = 1,N;
    
    OrderedStream(int n) {
        N = n;
        for(int i = 0; i <= n; i++){
            order.push_back(" ");
        }
    }
    
    vector<string> insert(int idKey, string value) {
        order[idKey] = value;
        vector<string> ans;
        while(idx <= N){
            if(order[idx] == " "){
                break;
            }
            else{
                ans.push_back(order[idx]);
            }
            idx++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */