class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> matches;
        
        for(int i = 0; i < words.size(); i++){
            unordered_map<char,char> m;
            bool f = 1;
            for(int j = 0; j < words[i].size() ; j++){
                if(words[i][j] == pattern[j]){
                    if(m.count(words[i][j]) == 0){
                        m[words[i][j]] = pattern[j];
                    }
                    else if(m[words[i][j]] == pattern[j]){
                        continue;
                    }
                    else{
                        f = 0;
                        break;
                    }
                }
                
                else{
                    if(m.count(words[i][j]) == 0){
                        for(auto &p : m){
                            if(p.second == pattern[j]){
                                f = 0;
                            }
                        }
                        if(f){
                            m[words[i][j]] = pattern[j];
                        }
                    }
                    else{
                        if(m[words[i][j]] != pattern[j]){
                            f = 0;
                        }
                    }
                }
            }
            if(f){
                matches.push_back(words[i]);
            }
        }
        
        return matches;
    }
};