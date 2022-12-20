class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        if(n < 10){
            return {};
        }
        unordered_map<string,int> counts;
        string temp = "";
        for(int i = 0; i < 10; i++){
            temp += s[i];
        }
        counts[temp]++;
        for(int i = 10; i < n; i++){
            temp.erase(0,1);
            temp += s[i];
            counts[temp]++;
        }
        for(auto &p : counts){
            if(p.second > 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};