class Solution {
public:
    bool detectCapitalUse(string w) {
        int n = w.size();
        int l = 0, u = 0;
        for(char &c : w){
            if(c >= 'a'){
                l++;
            }
            else{
                u++;
            }
        }
        if(u == n){
            return true;
        }
        if(l == n){
            return true;
        }
        if(u == 1 and w[0] >= 'A' and w[0] <= 'Z'){
            return true;
        }
        return false;
    }
};