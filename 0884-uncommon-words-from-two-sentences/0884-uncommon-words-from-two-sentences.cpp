class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> uncommons;
        
        unordered_map<string,int> mp,mp1;
        stringstream ss(s1);
        string temp;
        
        while(ss >> temp){
            mp[temp]++;
        }
        
        stringstream ss1(s2);
        while(ss1 >> temp){
            mp1[temp]++;
        }
        
        for(auto &i : mp){
            if(i.second == 1 and !mp1.count(i.first)){
                uncommons.push_back(i.first);
            }
        }
        
        for(auto &i : mp1){
            if(i.second == 1 and !mp.count(i.first)){
                uncommons.push_back(i.first);
            }
        }
        
        return uncommons;
    }
};