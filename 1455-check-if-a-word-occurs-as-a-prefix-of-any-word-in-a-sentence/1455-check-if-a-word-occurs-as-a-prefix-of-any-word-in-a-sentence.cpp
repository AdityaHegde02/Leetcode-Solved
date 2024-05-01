class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        
        int ind = 1;
        while(ss >> s){
            bool ok = 1;
            for(int i = 0; i < searchWord.size(); i++){
                if(searchWord[i] != s[i]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                return ind;
            }
            ind++;
        }
        return -1;
    }
};