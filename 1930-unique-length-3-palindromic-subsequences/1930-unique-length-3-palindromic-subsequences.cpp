class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]].push_back(i);
        }
        
        vector<pair<int,int>> q;
        for(auto &i : mp){
            if(i.second.size() >= 2){
                int sz = i.second.size();
                pair<int,int> a = {i.second[0],i.second[sz - 1]};
                q.push_back(a);
            }
        }
        
        int ans = 0;
        for(auto &i : q){
            int start = i.first, end = i.second;
            unordered_set<char> st;
            for(int j = start + 1; j < end; j++){
                st.insert(s[j]);
            }
            ans += st.size();
        }
        
        return ans;
    }
};