class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto &i : words){
            for(auto &j : i){
                mp[j]++;
            }
        }
        
        for(auto &i : mp){
            if((i.second) % (words.size()) != 0){
                return 0;
            }
        }
        
        return 1;
    }
};