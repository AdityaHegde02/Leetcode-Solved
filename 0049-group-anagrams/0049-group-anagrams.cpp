class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> isThere;
        vector<vector<string>> ans;
        
        for(string &i : strs){
            string key = i;
            sort(i.begin(),i.end());
            isThere[i].push_back(key);
        }
        
        for(auto &i : isThere){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};