class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> mp;
        vector<string> a(n);
        for(int i = 0; i < n; i++){
            string s = "";
            for(int j = 1; j < words[i].size(); j++){
                int d = words[i][j] - words[i][j-1];
                s += to_string(d) + '#';
            }
            a[i] = s;
            mp[s]++;
        }
        for(auto &i : mp){
            if(i.second == 1){
                for(int j = 0; j < n; j++){
                    if(a[j] == i.first){
                        return words[j];
                    }
                }
            }
        }
        return "";
    }
};