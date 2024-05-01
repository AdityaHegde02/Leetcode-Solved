class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, n = word.size();
        
        while(i < n and word[i] != ch){
            i++;
        }
        
        if(i == n){
            return word;
        }
        
        int j = 0;
        while(j <= i){
            swap(word[j++],word[i--]);
        }
        
        return word;
    }
};