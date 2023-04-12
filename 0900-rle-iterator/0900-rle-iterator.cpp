class RLEIterator {
public:
    vector<int> encode;
    int i = 0;
    bool f = 0;
    
    RLEIterator(vector<int>& encoding) {
        for(int &i : encoding){
            encode.push_back(i);
        }
    }
    
    int next(int n) {
        if(f){
            return -1;
        }
        
        for(int j = i; j < encode.size(); j += 2){
            if(n - encode[j] > 0){
                n -= encode[j];
            }
            else if(n == encode[j]){
                i = j + 2;
                return encode[j + 1];
            }
            else{
                encode[j] -= n;
                i = j;
                return encode[j + 1];
            }
        }
        
        f = 1;
        
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */