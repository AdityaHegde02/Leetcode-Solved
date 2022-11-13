class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        stringstream ss(s);
        string word;
        while(ss >> word ){
            words.push_back(word);
        }

        string ans;
        int n = words.size();
        
        for(int i = n - 1 ; i > 0 ; i--){
            ans += (words[i]) + ' ';
        }
        
        ans += words[0];
        
        return ans;
    }
};