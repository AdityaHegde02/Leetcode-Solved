class Solution {
public:
    int strStr(string h, string g) {
        int m = h.size(), n = g.size();
        string temp = "";
        for(int i = 0; i < n; i++){
            temp += h[i];
        }
        
        if(temp == g){
            return 0;
        }
        
        for(int k = n; k < m; k++){
            temp.erase(0,1);
            temp += h[k];
            if(temp == g){
                return k - n + 1;
            }
        }
        
        return -1;
    }
};