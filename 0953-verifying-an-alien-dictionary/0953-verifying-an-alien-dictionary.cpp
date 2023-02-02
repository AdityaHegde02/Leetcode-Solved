class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char,int> mp;
        for(int i = 0; i < 26; i++){
            mp[order[i]] = i;  
        }
        bool ok = 1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = 0; k < min(words[i].size(),words[j].size()); k++){
                    if(k == min(words[i].size(),words[j].size()) - 1 and words[i][k] == words[j][k]){
                        if(words[i].size() > words[j].size()){
                            ok = 0;
                        }    
                    }
                    if(mp[words[i][k]] < mp[words[j][k]]){
                        break;
                    }
                    else if(mp[words[i][k]] > mp[words[j][k]]){
                        ok = 0;
                        break;
                    }
                }
                if(!ok){
                    break;
                }
            }
        }
        
        return ok;
    }
};