class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    
    void solve(int i,string &s,string &temp){
        if(i >= s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }
        
        string t = temp;
        for(int j = 1; j <= s.size() and i + j <= s.size(); j++){
            string left = s.substr(i,j);
            if(st.count(left)){
                temp += left + " ";
                solve(i + j,s,temp);
                temp = t;
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &i : wordDict){
            st.insert(i);
        }
        
        string temp = "";
        solve(0,s,temp);
        return ans;
    }
};