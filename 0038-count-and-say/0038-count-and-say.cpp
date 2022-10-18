class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        
        string prev = countAndSay(n-1);
        
        int sz = prev.size();
        int j = 0;
        string next;
        for(int i = 0; i < sz;){
            j = i;
            while(j < sz - 1 and prev[j] == prev[j + 1]){
                j++;
            }
            int times = j - i + 1;
            next += to_string(times);
            next += prev[j];
            i = j+1;
        }
        
        return next;
    }
};