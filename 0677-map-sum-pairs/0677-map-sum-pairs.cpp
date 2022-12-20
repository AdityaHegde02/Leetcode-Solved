class MapSum {
public:
    unordered_map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string pre) {
        int sum = 0;
        for(auto &j : mp){
            string x = j.first;
            bool f = 1;
            if(x.size() < pre.size()){
                continue;
            }
            for(int i = 0; i < pre.size(); i++){
                if(pre[i] != x[i]){
                    f = 0;
                }
            }
            if(f){
                sum += (j.second);
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */