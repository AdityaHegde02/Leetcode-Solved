class Solution {
public:
    bool wordPattern(string p, string s) {
        int m = p.size();
        unordered_map<char,string> mp;      // to map
        stringstream ss(s);
        string word;
        vector<string> words;
        unordered_map<string,bool> isMapped;  // to check if word is already mapped
        while(ss >> word){
            words.push_back(word);
        }
        if(words.size() != m){
            return false;
        }
        for(int i = 0; i < m; i++){
            if(mp.find(p[i]) == mp.end()){
                if(isMapped.find(words[i]) != isMapped.end()){
                    return false;
                }
                mp[p[i]] = words[i];
                isMapped[words[i]] = 1;
            }
            else{
                if(words[i] != mp[p[i]]){
                    return false;
                }
            }
        }
        return true;
    }
};