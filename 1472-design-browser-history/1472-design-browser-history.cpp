class BrowserHistory {
public:
    vector<string> a;
    int curr = 0;
    
    BrowserHistory(string homepage) {
        a.push_back(homepage);
    }
    
    void visit(string url) {
        int n = a.size();
        auto it = a.begin();
        auto x = it + curr + 1;
        a.erase(x,a.end());
        a.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        if(steps <= curr){
            string ans = a[curr - steps];
            curr -= steps;
            return ans;
        }
        
        curr = 0;
        return a[0];
    }
    
    string forward(int steps) {
        int n = a.size();
        if(curr + steps < n){
            string ans = a[curr + steps];
            curr += steps;
            return ans;
        }
        
        curr = n - 1;
        return a[n - 1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */