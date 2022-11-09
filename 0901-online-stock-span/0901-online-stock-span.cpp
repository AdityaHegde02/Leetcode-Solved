class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {

    }
    
    int next(int price) {
        int ans = 1;
        if(s.empty()){
            s.push({price,1});
        }
        else{
            if(s.top().first > price){
                s.push({price,1});
            }
            else{
                while(!s.empty() and s.top().first <= price){
                    ans += s.top().second;
                    s.pop();
                }
                s.push({price,ans});
            }
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */