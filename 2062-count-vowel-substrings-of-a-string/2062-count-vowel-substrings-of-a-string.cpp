class Solution {
public:
    vector<char> vowels = {'a','e','i','o','u'};
    
    bool check(vector<int> &count){
        for(int i = 0; i < 5; i++){
            if(!count[vowels[i]-'a']){
                return false;
            }
        }
        return true;
    }
    
    int countVowelSubstrings(string word) {
        int n = word.size();
        if(n < 5){
            return 0;
        }
        int c = 0;
    
        for(int i = 0; i < n; i++){
            vector<int> count(26,0);
            for(int j = i;j < n; j++){
                if(word[j] != 'a' and word[j] != 'e' and word[j] != 'i' and word[j] != 'o' and word[j] != 'u'){
                    break;
                }
                else{
                    count[word[j] -'a']++;
                    if(check(count)){
                        while(j < n){
                            if(word[j] != 'a' and word[j] != 'e' and word[j] != 'i' and word[j] != 'o' and word[j] != 'u'){
                                break;
                            }
                            j++;
                            c++;
                        }
                        break;
                    }
                }
            }
        }
        
        return c;
    }
};