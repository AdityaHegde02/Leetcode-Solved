class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> isThere;
        vector<vector<string>> ans;
        
        for(string &i : strs){
            vector<int> count(26,0);
            for(char &j:i){
                count[j - 'a']++;
            }
            string key;
            for(auto &x : count){
                key += to_string(x) + " ";
            }
            isThere[key].push_back(i);
        }
        
        for(auto &i : isThere){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};