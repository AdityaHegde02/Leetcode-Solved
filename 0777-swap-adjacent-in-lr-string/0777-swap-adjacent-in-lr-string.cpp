class Solution {
public:
    bool canTransform(string s, string t) {
        int n = s.size();
        int i = 0, j = 0;
        while(i <= n or j <= n){
            while(i < n and s[i] == 'X'){
                i++;
            }
            while(j < n and t[j] == 'X'){
                j++;
            }
            
            if(i == n and j == n){
                return true;
            }
            
            if((i < n and j >= n) or (i >= n and j < n) or s[i] != t[j]){
                return false;
            }
            
            if(s[i] == 'L' and i < j){
                return false;
            }
            
            if(s[i] == 'R' and i > j){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};