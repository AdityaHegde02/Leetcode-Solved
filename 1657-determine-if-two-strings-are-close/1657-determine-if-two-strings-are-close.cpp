class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m != n){
            return false;
        }
        vector<int> count1(26,0),count2(26,0);
        for(char &c : word1){
            count1[c - 'a']++;
        }
        for(char &c : word2){
            count2[c - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if((count1[i] and !count2[i]) or (!count1[i] and count2[i])){
                return false;
            }
        }
        
        sort(count1.begin(),count1.end());
        sort(count2.begin(),count2.end());
        
        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};