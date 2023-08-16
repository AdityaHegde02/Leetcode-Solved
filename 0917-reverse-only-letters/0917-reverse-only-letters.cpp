class Solution {
public:
    bool isAlpha(int i,string &s){
        if((s[i] >= 'A' and s[i] <= 'Z') or s[i] >= 'a' and s[i]<='z'){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            bool a = isAlpha(i,s), b = isAlpha(j,s);
            if(a and b){
                swap(s[i++],s[j--]);
            }
            else if(a){
                j--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};