class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
            return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int v = 0;
        for(int i = 0; i < s.size()/2 ; i++){
            if(isVowel(s[i])){
                v++;
            }
        }
        for(int i = s.size()/2; i < s.size(); i++){
            if(isVowel(s[i])){
                v--;
            }
        }
        return (v == 0)?1:0;
    }
};