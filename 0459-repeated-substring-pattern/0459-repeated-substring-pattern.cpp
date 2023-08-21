class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        
        for(int len = 1; len <= (m/2); len++){
            int i = 0;
            string start = s.substr(0,len);
            if((m % len) != 0){
                continue;
            }
            i += len;
            while(i < m){
                string curr = s.substr(i,len);
                if(curr != start){
                    break;
                }
                else{
                    i += len;
                }
            }
            if(i >= m){
                return true;
            }
        }
        return false;
    }
};